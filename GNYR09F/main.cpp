#include <iostream>

using namespace std;
long long dp[102][102];
void solve(int n,int k)
{
    dp[0][0]=1;
    dp[1][0]=2;
    int i,j;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-2][j];
            if(j!=0)
                dp[i][j]+= dp[i-1][j-1]-dp[i-2][j-1];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    solve(101,101);
    cin>>t;
    while(t--)
    {
        int i,n,k;
        cin>>i>>n>>k;
        long long ans =dp[n][k];
        cout<<i<<" ";
        cout<<ans<<"\n";
    }
    return 0;
}
