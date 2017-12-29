#include <iostream>
#include <vector>
using namespace std;

vector< string > grid;

int vis[101][101];
string a = "ALLIZZWELL";
bool solve(int x,int y,int n,int m,int in)
{
    if(in==a.size())
        return true;
    int i,j;
    vis[x][y]=1;
    bool ans = false;
    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if(i==0 && j==0)
                continue;
            if(x+i>=0 && x+i<n && y+j>=0 && y+j<m && grid[x+i][y+j]==a[in] && !vis[x+i][y+j])
                ans =ans || solve(x+i,y+j,n,m,in+1);
        }
    }
    vis[x][y]=0;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        grid.clear();
        int n,m;
        cin>>n>>m;
        int i;
        for(i=0;i<n;i++)
        {
            string s;
            cin>>s;
            grid.push_back(s);
        }
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='A')
                    ans =ans || solve(i,j,n,m,1);
            }
        }
        cout<<(ans?"YES":"NO" )<<"\n";
    }
    return 0;
}
