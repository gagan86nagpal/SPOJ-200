#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int mouse[101][101],cat1[101][101],cat2[101][101];
int vis[101][101];
queue  < pair <int, pair <int,int > > > q;
void bfs(int x[101][101],int sx,int sy,int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        vis[i][j]=0;
    while(!q.empty())
        q.pop();
    vis[sx][sy]=1;
    q.push({0,{sx,sy}});
    x[sx][sy]=0;
    while(!q.empty())
    {
        pair <int,pair <int,int> > p= q.front();
        q.pop();
        int px = p.second.first;
        int py =p.second.second;
        int t = p.first;
        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                if( px+i<1 || px+i>n || py+j<1 || py+j>m || abs(i) +abs(j)!=1 || vis[px+i][py+j]==1 )
                    continue;
                x[px+i][py+j]=t+1;
                vis[px+i][py+j]=1;
                q.push({t+1,{px+i,py+j}});
            }
        }
    }
}

void print(int x[101][101],int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<x[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}
bool check(int n,int m)
{
    int i;
    for(i=1;i<=m;i++)
        if(mouse[1][i]<min(cat1[1][i],cat2[1][i]))
            return true;
    for(i=1;i<=m;i++)
        if(mouse[n][i]<min(cat1[n][i],cat2[n][i]))
            return true;
    for(i=1;i<=n;i++)
        if(mouse[i][1]<min(cat1[i][1],cat2[i][1]))
            return true;
    for(i=1;i<=n;i++)
        if(mouse[i][m]<min(cat1[i][m],cat2[i][m]))
            return true;

    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int t;
    cin>>t;
    while(t--)
    {
        int ax,ay,bx,by,cx,cy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        bfs(mouse,ax,ay,n,m);
        bfs(cat1,bx,by,n,m);
        bfs(cat2,cx,cy,n,m);
        bool ans = check(n,m);
        cout<<(ans?"YES":"NO")<<"\n";
    //    print(mouse,n,m);
     //   print(cat1,n,m);
      //  print(cat2,n,m);
    }
    return 0;
}
