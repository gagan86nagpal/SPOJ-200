#include <iostream>

using namespace std;
int a[21][21];
long long dp[1<<22];
long long solve(int n,int b=0)
{
    int i = __builtin_popcount(b);
    if(dp[b]!=-1)
        return dp[b];
    if(i==n)
        return dp[b]=1ll;
    int j=0;
    long long ans=0;
    for(j=0;j<n;j++)
    {
        if( (b & 1<<j)==0  && a[i][j] )
            ans+=solve(n,b|(1<<j));
    }
    return dp[b]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,j;
        for(i=0;i<=(1<<n);i++)
            dp[i]=-1;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j];

        long long ans = solve(n,0);
        cout<<ans<<"\n";
    }
    return 0;
}
