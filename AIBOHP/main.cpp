#include <iostream>
using namespace std;
string s;

int dp[6101][6101];
int solve(int st,int en)
{
    if(dp[st][en]!=-1)
        return dp[st][en];
    if(st>=en)
        return dp[st][en]=0;
    if(s[st]==s[en])
        return dp[st][en]=solve(st+1,en-1);
    else
        return dp[st][en]=1+min(solve(st+1,en),solve(st,en-1) );
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int i,j;
        for(i=0;i<s.size();i++)
            for(j=0;j<s.size();j++)
                dp[i][j]=-1;
        int ans = solve(0,s.size()-1);
        cout<<ans<<"\n";
    }
    return 0;
}
