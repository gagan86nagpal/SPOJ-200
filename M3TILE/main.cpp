#include <iostream>

using namespace std;
long long int dp[35];

long long int dp2[35];
int main()
{

    dp[1]=0;
    dp[2]=2;

    for(int i=3;i<=30;i++)
        dp[i]=dp[i-1]*4 - dp[i-2];
    dp2[1]=3;
    for(int i=2;i<=15;i++)
        dp2[i]=dp2[i-1]*3 +dp[i];
    dp2[0]=1;
    while(true)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        if(n&1)
            cout<<0<<"\n";
        else
        cout<<dp2[n/2]<<"\n";
    }
    return 0;
}
