#include <iostream>
#include <utility>
using namespace std;

int a[101];
pair<int,int>dp[102][102];
pair <int,int> solve(int s,int e)
{
    if(s==e)
        return {0,a[s]};
    if(dp[s][e].first!=-1)
        return dp[s][e];
    int i;
    pair <int,int> ret;
    for(i=s;i<e;i++)
    {
        pair <int,int> p1= solve(s,i);
        pair<int,int> p2 = solve(i+1,e);
        int smoke =p1.first+p2.first+p1.second*p2.second;
        int mix= (p1.second+p2.second)%100;
        if(ret.first>smoke ||i==s)
            ret = {smoke,mix};
    }
    return dp[s][e]= ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]={-1,-1};
        for(int i=0;i<n;i++)
            cin>>a[i];
        pair<int,int> ans  = solve(0,n);
        cout<<ans.first<<"\n";
    }
    return 0;
}
