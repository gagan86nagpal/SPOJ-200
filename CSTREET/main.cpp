#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int id[1002];
int root(int i)
{
    if(id[i]!=i)
        return id[i]= root(id[i]);
    return i;
}
void unite(int a,int b)
{
    a=root(a);
    b=root(b);
    if(a!=b)
        id[a]=b;
}
vector < pair< int, pair <int,int> > > edges;
int mst()
{
    int i;
    int ret=0;
    sort(edges.begin(),edges.end());
    for(i=0;i<edges.size();i++)
    {
        int a,b,w;
        w = edges[i].first;
        a = edges[i].second.first;
        b = edges[i].second.second;
        if(root(a)==root(b)) // cycle
            continue;
        ret+=w;
        unite(a,b);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int p,n,m;
        cin>>p>>n>>m;
        edges.clear();
        int i;
        for(i=1;i<=n;i++)
            id[i]=i;
        for(i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            edges.push_back({w,{a,b}});
        }

        int ans = p*mst();
        cout<<ans<<"\n";
    }
    return 0;
}
