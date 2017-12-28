#include <iostream>

using namespace std;
int dp[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    while(true)
    {
        int n,k;
        cin>>n>>k;
        if(n==0 && k==0)
            break;
        dp[1]=1;
        int i;
        for(i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+k;
            if(dp[i]>i)
                dp[i]=(dp[i-1] -1 + k)%i +1;
        }
        cout<<n<<" "<<k<<" ";
        cout<<dp[n]<<"\n";
    }
    return 0;
}
