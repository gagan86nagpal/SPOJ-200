#include <iostream>
#include <vector>
using namespace std;
int dp[52][1003];
vector< pair <int,int> > bags;
int solve(int i,int n,int w)
{
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(i==n)
        return dp[i][w]=0;
    if(bags[i].first<=w)
        return dp[i][w]=max(solve(i+1,n,w),solve(i+1,n,w-bags[i].first) +bags[i].second );
    else
        return dp[i][w]=solve(i+1,n,w);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        bags.clear();
        int w,n;
        cin>>w>>n;
        int i;
        for(i=0;i<=n;i++)
            for(int j=0;j<=w;j++)
                dp[i][j]=-1;
        for(i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            bags.push_back({a,b});
        }
        int ans = solve(0,n,w);
        cout<<"Hey stupid robber, you can get "<<ans<<".\n";
    }
    return 0;
}
