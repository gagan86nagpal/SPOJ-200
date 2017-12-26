#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector < pair <int, pair <int,int> > > edges;

int parent[10004];
int root(int i)
{
    if(parent[i]!=i)
        return parent[i]=root(parent[i]);
    return i;
}
void unite(int a,int b)
{
    a= root(a);
    b = root(b);
    if(a!=b)
        parent[a]=parent[b];
}
long long int kruskal(int n)
{
    long long ret=0;
    for(pair <int,pair <int,int> > e: edges)
    {
        int w= e.first;
        int a= e.second.first;
        int b = e.second.second;
        if(root(a)!=root(b))
            ret+=w,unite(a,b);
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
        edges.clear();
        int n;
        int i;
        cin>>n;
        for(i=1;i<=n;i++)
            parent[i]=i;
        for(i=1;i<=n;i++)
        {
            string _;
            cin>>_;
            int m;
            cin>>m;
            while(m--)
            {
                int b,w;
                cin>>b>>w;
                edges.push_back({w,{i,b}});
            }
        }
        sort(edges.begin(),edges.end());
        long long ans = kruskal(n);
        cout<<ans<<"\n";
    }
    return 0;
}
