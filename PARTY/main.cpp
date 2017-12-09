#include <iostream>
#include <utility>
using namespace std;
int cost[101];
int fun[101];
pair<int,int> dp[502][101];
pair<int,int> solve(int b,int i,int n)
{
    if(i==n) // no more items
        return {0,0};
    if(dp[b][i]!=make_pair(-1,-1))
        return dp[b][i];
    if(cost[i]<=b) // I can take this
    {
        pair<int,int> take = solve(b-cost[i],i+1,n);
        pair<int,int > donttake = solve(b,i+1,n);
        if(take.first + fun[i] > donttake.first ||(take.first+fun[i]==donttake.first && take.second+cost[i]<donttake.second) )
            return dp[b][i]={take.first+fun[i],take.second+cost[i]};
        else
            return dp[b][i]=solve(b,i+1,n);
    }
    return dp[b][i]=solve(b,i+1,n);
}
int main()
{
    while(true)
    {
        int b,n;
        cin>>b>>n;
        if(b==n&&n==0)
            break;
        int i,j;
        for(i=0;i<=b;i++)
            for(j=0;j<=n;j++)
                dp[i][j]={-1,-1};
        for(i=0;i<n;i++)
            cin>>cost[i]>>fun[i];

        pair<int,int> ans=solve(b,0,n);
        cout<<ans.second<<" "<<ans.first<<"\n";
    }
    return 0;
}
