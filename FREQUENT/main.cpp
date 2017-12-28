#include <iostream>

using namespace std;

struct block
{
    int ans;
    int la;
    int ra;
};
block segtree[400002];
int a[100002];

void build(int node,int l,int r)
{
    if(l==r)
    {
        segtree[node].la=segtree[node].ra=segtree[node].ans=1;
        return ;
    }
    int m =  (l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    if(a[l]==a[m+1]) // left segment
        segtree[node].la= segtree[2*node].la + segtree[2*node+1].la;
    else
        segtree[node].la =segtree[2*node].la;
    if(a[r]==a[m])
         segtree[node].ra= segtree[2*node].ra + segtree[2*node+1].ra;
    else
        segtree[node].ra =segtree[2*node+1].ra;
    segtree[node].ans = max(segtree[2*node].ans,segtree[2*node+1].ans);
    if(a[m]==a[m+1])
        segtree[node].ans = max(segtree[node].ans,segtree[2*node].ra + segtree[2*node+1].la);
}

block query(int node,int l,int r,int ql,int qr)
{
    if(ql>r || qr<l)
    return {0,0,0};
    if(ql<=l && qr>=r)
        return segtree[node];
    int  m = (l+r)/2;
    block b1 = query(2*node,l,m,ql,qr);
    block b2 = query(2*node+1,m+1,r,ql,qr);
    block b;
    if(a[l]==a[m+1]) // left segment
        b.la= b1.la + b2.la;
    else
        b.la =b1.la;
    if(a[r]==a[m])
         b.ra= b1.ra + b2.ra;
    else
        b.ra =b2.ra;
    b.ans = max(b1.ans,b2.ans);
    if(a[m]==a[m+1])
        b.ans = max(b.ans,b1.ra + b2.la);
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        cin>>q;
        int i;
        for(i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            block b1 = query(1,1,n,a,b);
            cout<<b1.ans<<"\n";
        }
    }

    return 0;
}
