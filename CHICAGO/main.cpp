#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
using namespace std;

vector < pair <int,double > > adj[102];
double prob[102];
double dijkstra(int source,int n)
{
    set < pair <double,int> > s;
    int i;
    for(i=1;i<=n;i++)
        prob[i]=0;
    prob[source]=1.0;
    s.insert({prob[source],source});
    while(!s.empty())
    {
        pair <double ,int > p = *s.rbegin();
        if(p.second==n)
            return p.first;
        s.erase(*(--s.end()));
        for(pair <int,double > node: adj[p.second])
        {
            if(prob[p.second]*node.second > prob[node.first])
                prob[node.first]=prob[p.second]*node.second, s.insert({prob[node.first],node.first});
        }
    }
    return 0;
}
int main()
{
    int n,m;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&m);
        int i;
        for(i=0;i<=n;i++)
            adj[i].clear();
        for(i=0;i<m;i++)
        {
            int a,b;
            double c;
            scanf("%d %d %lf",&a,&b,&c);
            c/=100.0;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        double ans = dijkstra(1,n);
        printf("%.6f percent\n",ans*100);
    }
     return 0;
}
