#include <iostream>

using namespace std;
int dp[1002][1002];
int a[1002];
int solve(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j)
        return dp[i][j]=a[i];
    if(i>j)
        return dp[i][j]=0;
    // 1 st choice , take i
    int val1;
    if(a[i+1]>=a[j])
        val1 =solve(i+2,j) + a[i]-a[i+1];
    else
        val1 = solve(i+1,j-1) +a[i]-a[j];

    //2nd choice , take j
    int val2;
    if(a[i]>=a[j-1])
        val2 = solve(i+1,j-1) + a[j] - a[i];
    else
        val2 = solve(i,j-2) + a[j] - a[j-1];
    return dp[i][j]= max(val1,val2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int tc=0;
    while(true)
    {
            tc++;
        int n;
        cin>>n;
        if(n==0)
            break;
        int i,j;
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                dp[i][j]=-1;
        for(i=0;i<n;i++)
            cin>>a[i];
        int ans = solve(0,n-1);
        cout<<"In game "<<tc<<", the greedy strategy might lose by as many as "<<ans<<" points.\n";
    }
    return 0;
}
