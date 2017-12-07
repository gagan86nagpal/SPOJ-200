#include <iostream>

using namespace std;

#define inf 16000000
int a[50002];
struct block
{
    int sum;
    int pref;
    int post;
    int ans;
};
block segtree[200008];
void build(int node ,int l ,int r)
{
    if(l==r)
    {
        segtree[node]= {a[l],a[l],a[l],a[l]};
        return;
    }
    int mid = (l+ r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    block ls = segtree[2*node];
    block rs = segtree[2*node+1];
    segtree[node]= {ls.sum+rs.sum,max(ls.pref,ls.sum+rs.pref),max(rs.post,rs.sum+ls.post),max(ls.post+rs.pref,max(ls.ans,rs.ans))};
}

block query(int node,int l,int r ,int ql,int qr)
{
    if(qr < l || ql > r)  // out of range
        return {-inf,-inf,-inf,-inf};
    if(ql<=l && qr>=r)  // completely inside
        return segtree[node];
    int mid = (l+r)/2;
    block ls = query(2*node,l,mid,ql,qr);
    block rs = query(2*node+1,mid+1,r,ql,qr);
    return block {ls.sum+rs.sum,max(ls.pref,ls.sum+rs.pref),max(rs.post,rs.sum+ls.post),max(ls.post+rs.pref,max(ls.ans,rs.ans))};
}
int main()
{
    cin.tie(0);
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        block ans = query(1,1,n,l,r);
        cout<<ans.ans<<"\n";
    }
    return 0;
}
