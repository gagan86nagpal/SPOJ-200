#include <iostream>

using namespace std;
long long segtree[800004];
long long lazy[800004];
void print(long long n)
{
    long long i;
    for(i=1;i<=2*n;i++)
        cout<<segtree[i]<<" ";
    cout<<"\n";
    for(i=1;i<=2*n;i++)
        cout<<lazy[i]<<" ";
    cout<<"\n";
    for(i=1;i<=2*n;i++)
        cout<<i<<" ";
    cout<<"\n";
}
long long query(long long node,long long l,long long r,long long ql,long long qr)
{
    if(lazy[node]!=0)
    {
        segtree[node]+=(r-l+1)*lazy[node];
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        lazy[node]=0;
    }
    if(qr < l || ql > r) // outside
        return 0;

    if(ql<=l && qr>=r)
        return segtree[node];
    long long m = (l+r)/2;
    long long a = query(2*node,l,m,ql,qr);
    long long b = query(2*node+1,m+1,r,ql,qr);
    return a+b;
}
void update(long long node,long long l,long long r,long long ql,long long qr,long long v)
{
     if(lazy[node]!=0)
    {
        segtree[node]+=(r-l+1)*lazy[node];
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        lazy[node]=0;
    }
    if(qr<l || ql>r) // outside
        return;
    if(ql<=l && qr>=r) // completely inside
    {
        segtree[node]+=(r-l+1)*v;
        lazy[2*node]+=v;
        lazy[2*node+1]+=v;
        return ;
    }

    long long m = (l+r)/2;
    update(2*node,l,m,ql,qr,v);
    update(2*node+1,m+1,r,ql,qr,v);
    segtree[node]=segtree[2*node] + segtree[2*node+1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,c;
        cin>>n>>c;
        for(long long i=0;i<=8*n;i++)
            segtree[i]=0,lazy[i]=0;
        while(c--)
        {
            long long a;
            cin>>a;
            if(a==0)
            {
                long long p,q,v;
                cin>>p>>q>>v;
                update(1,1,n,p,q,v);
                // print(n);
            }
            else
            {
                long long p,q;
                cin>>p>>q;
                long long ans = query(1,1,n,p,q);
               // print(n);
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
