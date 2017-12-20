#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define inf 200000
map <string,int> m;
vector < pair <int,int> > graph[10002];
multiset < pair<int,int> > pq;
int dist[10002];
int dijkstra(int n,int s,int t)
{
    pq.clear();
    int i;
    for(i=1;i<=n;i++)
        dist[i]=inf;
    dist[s]=0;
    pq.insert({0,s});
    while(!pq.empty())
    {
        pair <int,int> p = *pq.begin();
        pq.erase(pq.begin());
        int a= p.second;
        if(t==a)
            return p.first;
        for(pair<int,int> node : graph[a])
        {
            int w = node.second;
            int b = node.first;
            if(dist[a] + w < dist[b])
            {
                dist[b]=w+dist[a];
                pq.insert({dist[b],b});
            }
        }
    }
    return inf;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int i;
        cin>>n;
        for(i=1;i<=n;i++)
            graph[i].clear();
        m.clear();
        for(i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            m[s]=i;
            int m;
            cin>>m;
            int j;
            for(j=0;j<m;j++)
            {
                int a,w;
                cin>>a>>w;
                graph[i].push_back({a,w});
            }
        }
        int tc;
        cin>>tc;
        for(i=0;i<tc;i++)
        {
            string so,ta;
            cin>>so>>ta;
            int s,t;
            s= m[so];
            t = m[ta];
            int ans=dijkstra(n,s,t);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
