#include <iostream>

using namespace std;
int a[100002];
int segtree[400002];
int inf = 1000000004;
void build(int node,int l,int r)
{
    if(l==r)
    {
        segtree[node]=a[l];
        return ;
    }
    int m=(l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    segtree[node] = min(segtree[2*node],segtree[2*node+1]);
}
int query(int node,int l,int r,int ql,int qr)
{
    if(qr<l || ql >r)
        return inf;
    if(ql<=l && qr >= r)
        return segtree[node];
    int m = (l+r)/2;
    int s1 = query(2*node,l,m,ql,qr);
    int s2 = query(2*node+1,m+1,r,ql,qr);
    return min(s1,s2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        tc++;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
            cout<<"Scenario #"<<tc<<":\n";
        while(m--)
        {
            int l,r;
            cin>>l>>r;
            int ans = query(1,1,n,l,r);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
