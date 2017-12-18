#include <iostream>

using namespace std;
long long a[3][100002],dp[3][100002];

#define inf 100000000000000ll
long long solve(int c,int r,int n)
{
    if(c==1 && r==n-1)
        return a[c][r];
    if(r==n)
        return inf;
    if(dp[c][r]!=inf)
        return dp[c][r];
    if(c==0)
    {
        return dp[c][r]=a[c][r]+min(solve(1,r,n),min(solve(1,r+1,n),solve(0,r+1,n)));
    }
    else if(c==1)
    {
        return dp[c][r]=a[c][r]+min(min(solve(2,r,n),solve(1,r+1,n)),min(solve(0,r+1,n),solve(2,r+1,n)));
    }
    else
        return dp[c][r]=a[c][r]+min(solve(2,r+1,n),solve(1,r+1,n));
}
int main()
{
    ios_base::sync_with_stdio(false);
    for(int i=1;true;i++)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int j,k;
        for(k=0;k<=n;k++)
            for(j=0;j<3;j++)
                dp[j][k]=inf;
        for(k=0;k<n;k++)
            for(j=0;j<3;j++)
                cin>>a[j][k];
        long long ans=solve(1,0,n);
        cout<<i<<". ";
        cout<<ans<<"\n";
    }
    return 0;
}
