#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define inf 100000000
vector < pair <int,int> > graph[102];
int dist[102];
void dijkstra(int n,int s)
{
    int i;
    for(i=1;i<=n;i++)
        dist[i]=inf;
    dist[s]=0;

    multiset< pair <int,int> > m;
    m.insert({dist[s],s});
    while(!m.empty())
    {
        pair <int,int> p = *m.begin();
        m.erase(m.begin());
        for(pair <int,int> node: graph[p.second])
        {
            if(dist[p.second]+ node.second <dist[node.first])
            {
                dist[node.first] = dist[p.second] + node.second;
                m.insert({dist[node.first],node.first});
            }
        }
    }
}

int main()
{
    int n,s,t,m;
    cin>>n>>s>>t;
    cin>>m;
    int i;
    for(i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[b].push_back({a,w});
    }
    dijkstra(n,s);
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        if(dist[i]<=t)
            cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}
