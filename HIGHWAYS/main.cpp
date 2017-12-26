#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define inf 1000000000000ll
long long dist[100003];
vector < pair <int,int > > adj[100002];
long long dijkstra(int s,int d,int n)
{
    set < pair <long long,int>  > pq;
    int i;
    for(i=1;i<=n;i++)
        dist[i]=inf;
    dist[s]=0;
    pq.insert({0,s});
    while(!pq.empty())
    {
        pair <long long,int> p = *pq.begin();
        pq.erase(pq.begin());
        int a= p.second;
        if(a==d)
            return p.first;
        for(pair<int,int>  node : adj[a])
        {
            int b = node.first;
            int w =node.second;
            if(dist[a] + w < dist[b])
            {
                dist[b] = dist[a]+ w;
                pq.insert({dist[b],b});
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,s,d;
        cin>>n>>m>>s>>d;
        while(m--)
        {
            int a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        long long ans = dijkstra(s,d,n);
        if(ans==-1)
            cout<<"NONE\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}
