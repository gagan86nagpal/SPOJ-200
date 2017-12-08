#include <iostream>

using namespace std;
long long  a[10002];
long long dp[10002];
long long solve(int i,int n)
{

    if(i>=n)
        return 0;
    if(dp[i]!=-1)
        return dp[i];

    return dp[i]=max(a[i] + solve(i+2,n) , solve(i+1,n));
}
int main()
{
    int t;
    cin>>t;
    int i;
    for(i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i],dp[i]=-1;
        long long ans = solve(0,n);
        cout<<"Case "<<i<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
