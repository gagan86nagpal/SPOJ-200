#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int prefix[203];
int dp[222][222];
int solve(int i,int j,int n)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    int l = 0;
    if(i>0)
        l = prefix[i-1];
    int n1=prefix[j]-l;
    if(n1 > (j-i+1)/2)
        return j-i+1;
    int ans = 0;
    for(int k=i;k<=j-1;k++)
    {
        ans = max(ans, solve(i,k,n) + solve(k+1,j,n));
    }
    return dp[i][j]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t;
    string a;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>a;
        int i;
        for(i=0;i<=n;i++)
            prefix[i]=0;
        prefix[0]=(a[0]=='1');
        for(i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        for(i=1;i<=n;i++)
            prefix[i]=prefix[i-1]+a[i]-'0';
       int ans = solve(0,n-1,n);
       cout<<ans<<"\n";
    }
    return 0;
}
