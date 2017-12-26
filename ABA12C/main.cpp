#include <iostream>

using namespace std;
int dp[102],price[102];
#define inf 100000000
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int _,n;
        cin>>_>>n;
        // _ is of no use as per test cases
        // while we have to take n apples
        int i;
        for(i=1;i<=n;i++)
            cin>>price[i];
        dp[1]=price[1];
        dp[0]=0;
        for(i=2;i<=n;i++)
        {
            int j;
            int ans =(price[i]==-1)?inf:price[i];
            for(j=i/2;j>=1 ;j--)
            {
                if(dp[j]!=-1 && dp[i-j]!=-1)
                    ans = min(ans,dp[j]+dp[i-j]);
            }
            dp[i]=(ans==inf)?-1:ans;
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
