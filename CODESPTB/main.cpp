#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int segtree[400003];
vector < pair <int,int> > b;
int query(int node,int l,int r,int ql,int qr)
{
    if(qr<l|| ql > r || l>r)
        return 0;
    if(ql<=l && qr>=r)
        return segtree[node];
    int m = (l+r)/2;
    int a= query(2*node,l,m,ql,qr);
    int b  = query(2*node+1,m+1,r,ql,qr);
    return a+b;
}
void update(int node,int l,int r,int i)
{
    if(l==r)
    {
        segtree[node]=1;
        return;
    }
    int m = (l+r)/2;
    if(m>=i)
        update(2*node,l,m,i);
    else
        update(2*node+1,m+1,r,i);
    segtree[node]= segtree[2*node]+ segtree[2*node+1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        b.clear();
        int n;
        cin>>n;
        int i;
        for(i=1;i<=4*n;i++)
            segtree[i]=0;
        for(i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            b.push_back({x,i});
        }
        sort(b.begin(),b.end());
        long long ans=0;
        for(pair <int,int> p :b)
        {
            int in = p.second;

            ans = ans + (long long)query(1,1,n,in+1,n);
               update(1,1,n,in);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
