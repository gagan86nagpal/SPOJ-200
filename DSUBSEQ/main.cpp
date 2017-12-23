#include <iostream>

using namespace std;
long long dp[100003];
long long pen[300];
int main()
{
    long long mod = 1000000007;
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int i;
        for(i=0;i<=s.size();i++)
            dp[i]=0;
        for(i=0;i<300;i++)
            pen[i]=0;
        dp[s.size()-1]=1;
        long long prev_sum=1;
        pen[s[s.size()-1]]=1;
        for(i=s.size()-2;i>=0;i--)
        {
            dp[i]=(prev_sum +1-pen[s[i]] + mod)%mod;
            pen[s[i]]+=dp[i];
            prev_sum+=dp[i];
            pen[s[i]]%=mod;
            prev_sum%=mod;
        }
        long long ans=0;
        for(i=0;i<s.size();i++)
            ans+=dp[i],ans%=mod;
        ans++;
        ans%=mod;
        cout<<ans<<"\n";
    }
    return 0;
}
