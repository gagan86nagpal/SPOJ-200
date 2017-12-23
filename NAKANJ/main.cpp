#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


int bfs(int sx,int sy,int tx,int ty)
{
    queue <pair <int,pair <int,int> > >q;
    q.push({0,{sx,sy}});
    while(!q.empty())
    {
        pair <int, pair <int,int> > pp =q.front();
        q.pop();
        int level= pp.first;
        int x =pp.second.first;
        int y = pp.second.second;
        if(x==tx && y==ty)
            return level;
        int i,j;
        for(i=-2;i<=2;i++)
        {
            for(j=-2;j<=2;j++)
            {
                if(abs(i)+abs(j)==3 && x+i>=0 && y+j>=0 && x+i<8&&y+j<8)
                    q.push({level+1,{x+i,y+j}});
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int si,sj;
        int ti,tj;
        si= s1[0]-'a';
        sj =s1[1]-'1';
        ti= s2[0]-'a';
        tj =s2[1]-'1';
        cout<<bfs(si,sj,ti,tj)<<"\n";
    }
    return 0;
}
