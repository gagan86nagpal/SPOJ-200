#include <iostream>

using namespace std;

long long dp[50020];
long long solve(string s,int in)
{
    if(s.size()==in)
        return 1;
    if(s.size()-in==1)
    {
        if(s[in]=='0')
            return 0;
        else
            return 1;
    }
    if(dp[in]!=-1)
        return dp[in];

    if(s[in]=='0')
        return dp[in]=0;
    else
    {
        long long ans =solve(s,in+1);
        int n = (s[in]-'0')*10   + s[in+1]-'0';
        if(n<=26)
            ans+=solve(s,in+2);
        return dp[in]=ans;
    }

}
void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        dp[i]=-1;
}
int main()
{
    string s;
    while(true)
    {
        cin>>s;
        if(s=="0")
            break;
        init(s.size());
        long long ans =solve(s,0);
        cout<<ans<<"\n";
    }
    return 0;
}
