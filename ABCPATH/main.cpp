#include <iostream>

using namespace std;
string a[51];
int dp[51][51];
int solve(int x,int y,int val,int n,int m)
{
    int i,j;
    int ret=0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if(x+i <n && y+j < m &&  x+i>=0 && y+j>=0 &&a[x+i][y+j]==val )
                    ret = max(ret,1+solve(x+i,y+j,val+1,n,m));
        }
    }
    return dp[x][y]=ret;
}
int main()
{
    int tc=0;
    while(true)
    {
        tc++;
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        int i,j;
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                dp[i][j]=-1;
        for(i=0;i<n;i++)
                cin>>a[i];
        int ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(a[i][j]==(int)'A')
                    ans= max(ans,1+solve(i,j,(int)'A'+1,n,m));
        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
    return 0;
}
