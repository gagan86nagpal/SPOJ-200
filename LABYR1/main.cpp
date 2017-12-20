#include <iostream>
#include <utility>
using namespace std;
string a[1002];
pair <int, pair <int,int> > dfs(int x,int y,int px,int py,int n,int m)
{
    int i,j;
    pair <int,pair<int,int > > ret = {0,{x,y}};
    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if( (i==0 )^ (j==0) )
            {
                if(x+i <n && x+i >=0 && y+j<m && y+j>=0 && a[x+i][y+j]=='.')
                {
                    if(x+i==px && y+j==py)
                        continue;
                    pair <int,pair <int,int> >  p = dfs(x+i,y+j,x,y,n,m);
                    if(p.first+1>ret.first)
                        ret={p.first+1,{p.second.first,p.second.second}};
                }
            }
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        int i,si,sj,j;
        cin>>m>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        bool flag = false;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='.')
                {
                    flag= true;
                    si=i;
                    sj=j;
                    break;
                }
            }
            if(flag)
                break;
        }
        pair <int,pair<int,int> > p =dfs(si,sj,-1,-1,n,m);
        pair <int,pair<int,int> > ans = dfs(p.second.first,p.second.second,-1,-1,n,m);
        cout<<"Maximum rope length is "<<ans.first<<".\n";

    }
    return 0;
}
