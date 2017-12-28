#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<pair<int,int> > a;
vector<string> b;
map <string,int> m;

int segtree[120002];
int query(int node,int l,int r,int ql,int qr)
{
    if(qr < l|| ql >r)
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
    if(i<=m)
        update(2*node,l,m,i);
    else
        update(2*node+1,m+1,r,i);
    segtree[node]=segtree[2*node]+segtree[2*node+1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        a.clear();b.clear();
        int n,i;
        cin>>n;
        for(i=0;i<=4*n;i++)
            segtree[i]=0;
        for(i=0;i<n;i++)
        {
            string x;
            cin>>x;
            b.push_back(x);
        }
        for(i=0;i<n;i++)
        {
            string x;
            cin>>x;
            m[x]=i+1;
        }
        int pos=0;
        for(string s:b)
            a.push_back({m[s],++pos});
        sort(a.begin(),a.end());
        int ans=0;
        for(pair <int,int> p :a)
        {
            ans+=query(1,1,n,p.second,n);
            update(1,1,n,p.second);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
