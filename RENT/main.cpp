#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair <pair <long long,long long > , long long> > orders;
bool cmp(pair <pair <long long,long long > , long long> p1 , pair <pair <long long,long long > , long long> p2)
{
    return p1.first.second < p2.first.second;
}
long long dp[10002];
long long bSearch(long long l,long long h,long long val)
{
    while(l<h)
    {
        long long m =(l+h)/2;
        if(orders[m].first.second<=val)
            l = m+1;
        else
            h = m;
    }
    return l-1;
}
long long solve(long long n)
{
    long long i,j;
    for(i=1;i<=n;i++)
    {
        j = bSearch(0,i,orders[i].first.first);
        dp[i]=max(dp[i-1],dp[j]+orders[i].second);
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        orders.clear();
        long long i;
        for(i=0;i<=n;i++)
            dp[i]=0;
        orders.push_back({{0,0},0});
        for(i=0;i<n;i++)
        {
            long long a,b,c;
            cin>>a>>b>>c;
            orders.push_back({{a,a+b},c});
        }
        sort(orders.begin(),orders.end(),cmp);
        long long ans = solve(n);
        cout<<ans<<"\n";
    }
    return 0;
}
