#include <iostream>

using namespace std;

int dp[20][100];
int solve(int n,int k)
{
    if(k<0)
        return 0;
    if(k==0)
        return 1;
    if(2*k> n*(n-1))
        return 0;
    if(dp[n][k]!=-1)
        return dp[n][k];
    int i ;
    int sum=0;
    for(i=0;i<n;i++)
        sum+=solve(n-1,k-i);
    return dp[n][k]=sum;
}
int main()
{
    int t;
    cin>>t;
    int i,j;
    for(i=0;i<=12;i++)
        for(j=0;j<=100;j++)
            dp[i][j]=-1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<"\n";
    }
    return 0;
}
