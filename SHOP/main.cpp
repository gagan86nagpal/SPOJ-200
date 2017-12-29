#include <iostream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
vector<string> grid;

// DFS is brute force , hence we should not use it
// Dijkstra is the optimal algorithm , I could think of.
int inf=600000;
int dis[30][30];

   set< pair <int, pair <int,int> > > s;
int dijkstra(int sx,int sy,int dx,int dy,int n,int m)
{
    s.clear();
   int i,j;
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        dis[i][j]=inf;
   dis[sx][sy]=0;
   s.insert( {dis[sx][sy],{sx,sy}});
   while(!s.empty())
   {
       pair < int, pair <int,int> > node = *s.begin();
       s.erase(s.begin());
       int x=node.second.first;
       int y=node.second.second;
       if(x==dx && y==dy)
            return node.first-('S'-'0');

       for(i=-1;i<=1;i++)
       {
           for(j=-1;j<=1;j++)
           {
               if(abs(i)+abs(j)==1 && x+i>=0 && y+j>=0 && x+i<n && y+j<m && grid[x+i][y+j]!='X')
               {
                   if(dis[x][y]+grid[x][y]-'0'< dis[x+i][y+j])
                        dis[x+i][y+j]=dis[x][y]+grid[x][y]-'0', s.insert({dis[x+i][y+j],{x+i,y+j}});
               }
           }
       }
   }
    return inf;
}
int main()
{
    ios_base::sync_with_stdio(false);
    while(true)
    {
        int r,c;
        cin>>c>>r;
        if(r==0 && c==0)
            break;
        int i,j;
            grid.clear();
        for(i=0;i<r;i++)
        {
            string st;
            cin>>st;
            grid.push_back(st);
        }
        int sx,sy,dx,dy;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]=='S')
                    sx=i,sy=j;
                if(grid[i][j]=='D')
                    dx=i,dy=j;
            }
        }
       int ans= dijkstra(sx,sy,dx,dy,r,c);
        cout<<ans<<"\n";

    }
    return 0;
}
