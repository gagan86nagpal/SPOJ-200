#include <iostream>

using namespace std;
int chamber[102][102];
int dp[102][102];
void print(int h,int w)
{
    int i,j;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
}
int solve(int i,int j,int h,int w)
{
    if(i==h-1)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret=0;
    if(j-1>=0)
        ret = max(ret,chamber[i+1][j-1]+solve(i+1,j-1,h,w));
    ret =max(ret,chamber[i+1][j] + solve(i+1,j,h,w));
    if(j+1<=w-1)
        ret  =max(ret,chamber[i+1][j+1]+solve(i+1,j+1,h,w));
    return dp[i][j]=ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h,w;
        cin>>h>>w;
        int i,j;
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                cin>>chamber[i][j],dp[i][j]=-1;
        int ans = -1;
        for(i=0;i<w;i++)
        {
            ans = max(ans ,chamber[0][i]+ solve(0,i,h,w));
        }
      //  print(h,w);
        cout<<ans<<"\n";
    }
    return 0;
}
