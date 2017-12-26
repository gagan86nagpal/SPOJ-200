#include <iostream>

using namespace std;
int segtree[400003];
int lazy[400003];
int query(int node,int l,int r,int ql,int qr)
{
        if(lazy[node]!=0)
    {
        segtree[node] = r-l+1 - segtree[node];
        lazy[2*node+1]^=1;
        lazy[2*node]^=1;
        lazy[node]=0;
    }
    if(qr < l || ql > r)
        return 0;

    if(ql <=l && qr >=r)
        return segtree[node];
    int m  = (l+r)/2;
    return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
}

void update(int node,int l,int r,int ql,int qr)
{
       if(lazy[node]!=0)
    {
        segtree[node] = r-l+1 - segtree[node];
        lazy[2*node+1]^=1;
        lazy[2*node]^=1;
        lazy[node]=0;
    }
    if(qr <l || ql>r)
        return ;

    if(ql<=l && qr>=r)
    {
        segtree[node] = r-l+1 - segtree[node];
        lazy[2*node+1]^=1;
        lazy[2*node]^=1;
        return;
    }
    int m = (l+r)/2;
    update(2*node,l,m,ql,qr);
    update(2*node+1,m+1,r,ql,qr);
    segtree[node] = segtree[2*node]+segtree[2*node+1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int q,a,b;
        cin>>q>>a>>b;
        if(q==0)
            update(1,1,n,a,b);
        else
        {
            int ans = query(1,1,n,a,b);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
