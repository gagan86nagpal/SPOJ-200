#include <iostream>

using namespace std;
// 1- losing state
//2 - winning state
int dp[1000002];
int k,l;
void calc(int n)
{
    int i;
    dp[1]=dp[k]=dp[l]=2;
    for(i=2;i<=n;i++)
    {
        if(dp[i]!=0)
            continue;
        if(i<k)
            dp[i]=3-dp[i-1];
        else if(i<l)
            if(dp[i-1]==1 ||dp[i-k]==1 )
                dp[i]=2;
            else
                dp[i]=1;
        else
            if(dp[i-1]==1 ||dp[i-k]==1 || dp[i-l]==1 )
                dp[i]=2;
            else
                dp[i]=1;
    }
}

int main()
{
    int m;
    string ans="";
    cin>>k>>l>>m;
    calc(1000000);
    while(m--)
    {
        int n;
        cin>>n;
        if(dp[n]==1)
            ans.push_back('B');
        else
            ans.push_back('A');
    }
    cout<<ans<<"\n";
    return 0;
}
