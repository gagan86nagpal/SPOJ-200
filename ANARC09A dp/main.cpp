#include <iostream>

using namespace std;
int dp[2002][2002];
string s;
int solve(int i,int cnt,int n)
{
    if(dp[i][cnt]!=-1)
        return dp[i][cnt];
    if(i==n)
        return dp[i][cnt]=cnt/2;
    if(s[i]=='{')
        return dp[i][cnt]=solve(i+1,cnt+1,n);
    else
    {
        if(cnt>0)
            return dp[i][cnt]=solve(i+1,cnt-1,n);
        else
            return dp[i][cnt]=1+solve(i+1,cnt+1,n);
    }
}
int main()
{
    int tc=0;
    while(true)
    {
        tc++;
        cin>>s;
        if(s[0]=='-')
            break;
        int n = s.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        int ans = solve(0,0,n);
        cout<<tc<<". "<<ans<<"\n";
    }
    return 0;
}
