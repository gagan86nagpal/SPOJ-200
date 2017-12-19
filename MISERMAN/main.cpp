#include <iostream>

using namespace std;
int dp[101][101];
int a[101][101];
int main()
{
   int n,m;
   cin>>n>>m;
   int i,j;
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        cin>>a[i][j];
   for(i=0;i<m;i++)
    dp[n-1][i]=a[n-1][i];
   for(i=n-2;i>=0;i--)
   {
       for(j=0;j<m;j++)
       {
           if(j==0)
           {
               dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
           }
           else if(j==m-1)
           {
               dp[i][j]=a[i][j] + min(dp[i+1][j],dp[i+1][j-1]);
           }
           else
           {
               dp[i][j]=a[i][j] + min(dp[i+1][j], min(dp[i+1][j-1],dp[i+1][j+1]));
           }
       }
   }
   int ans = dp[0][0];
   for(i=0;i<m;i++)
    ans = min(ans,dp[0][i]);
   cout<<ans<<"\n";
    return 0;
}
