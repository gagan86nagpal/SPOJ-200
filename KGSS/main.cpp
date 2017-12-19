#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


pair <int,int> segtree[400002];
int a[100002];

pair <int,int> getPair(pair <int,int> p1,pair <int,int> p2)
{
    vector<int> v;
    v.push_back(p1.first);
    v.push_back(p2.first);
    v.push_back(p1.second);
    v.push_back(p2.second);
    sort(v.begin(),v.end());
    return {v[2],v[3]};

}
void build(int node,int l,int r)
{
    if(l==r)
    {
        segtree[node]={-1,a[l]};
        return ;
    }
    int m = (l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    segtree[node] = getPair(segtree[2*node],segtree[2*node+1]);
}
pair <int,int> query(int node,int l,int r,int ql,int qr)
{
    if(qr<l || ql>r)
        return {-1,-1};
    if(ql<=l && qr>=r)
        return segtree[node];
    int m = (l+r)/2;
    pair<int,int> p1 = query(2*node,l,m,ql,qr);
    pair<int,int> p2 = query(2*node+1,m+1,r,ql,qr);
    return getPair(p1,p2);
}
void update(int node,int l,int r,int i,int x)
{
    if(l==r)
    {
        a[l]=x;
        segtree[node]={-1,x};
        return ;
    }
    int m = (l+r)/2;
    if(i<=m)
        update(2*node,l,m,i,x);
    else
        update(2*node+1,m+1,r,i,x);

    segtree[node] = getPair(segtree[2*node],segtree[2*node+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i];
    int q;
    cin>>q;
    build(1,1,n);
    while(q--)
    {
        string s;
        int l,r;
        cin>>s>>l>>r;
        if(s=="Q")
        {
            pair <int,int> ans = query(1,1,n,l,r);
            cout<<ans.first+ans.second<<"\n";
        }
        else
        {
            update(1,1,n,l,r);
        }
    }
    return 0;
}
