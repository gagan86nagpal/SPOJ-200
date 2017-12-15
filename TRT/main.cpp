#include <iostream>

using namespace std;
int dp[2001][2001];
int a[2001];
int solve(int i,int j ,int n)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int c= (n-j+i)*a[i]+solve(i+1,j,n);
    int b= (n-j+i)*a[j]+solve(i,j-1,n);
    return dp[i][j]=max(c,b);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    int ans = solve(0,n-1,n);
    cout<<ans<<"\n";
    return 0;
}
