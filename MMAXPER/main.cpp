#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int dp[2][1002];
vector < pair <int,int > > v;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    dp[0][n-1]=v[n-1].first ;
    dp[1][n-1]=v[n-1].second;
    for(i=n-2;i>=0;i--)
    {
        dp[0][i] =max(dp[0][i+1]+v[i].first + abs(v[i].second-v[i+1].second),dp[1][i+1] + v[i].first + abs(v[i].second-v[i+1].first));
        dp[1][i]=max(dp[0][i+1]+v[i].second + abs(v[i].first-v[i+1].second),dp[1][i+1] + v[i].second + abs(v[i].first-v[i+1].first));
    }
    cout<<max(dp[0][0],dp[1][0])<<"\n";
    return 0;
}
