#include <iostream>
#include <vector>
#include <utility>
using namespace std;
pair <int,bool> dp[502][10002];
vector <pair<int,int> > coins;

pair <int,bool> solve(int n,int W)
{
    if(W==0)
        return{0,true};
    if(dp[n][W].first!=-1)
        return dp[n][W];
    pair <int,bool> ret ={1e8,false};
    for(pair<int,int> coin : coins)
    {
        if(coin.second <= W) // we can take
        {
            pair <int,bool> sub =solve(n,W-coin.second);
            if(sub.second==true) // solved
            {
                if(ret.second==false || ret.first > sub.first+coin.first)
                    ret = {sub.first+coin.first,true};
            }
        }
    }
    return dp[n][W]=ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        coins.clear();
        int e,f;
        cin>>e>>f;
        int w = f-e;
        int n;
        cin>>n;
        int i;
        for(i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
                dp[i][j]={-1,false};
        }
        for(i=0;i<n;i++)
        {
            int money,weight;
            cin>>money>>weight;
            coins.push_back({money,weight});
        }
        pair <int,bool> ans = solve(n,w);
        if(ans.second)
            cout<<"The minimum amount of money in the piggy-bank is "<<ans.first<<".\n";
        else
            cout<<"This is impossible.\n";
    }
    return 0;
}
