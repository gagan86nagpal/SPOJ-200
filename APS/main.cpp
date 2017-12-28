#include <iostream>
#include <time.h>
using namespace std;
int sieve[10000002];
void precomp(int n)
{
    int i,j;
    for(i=2;i*i<=n;i++)
    {
        for(j=i*i;j<=n;j+=i)
            if(sieve[j]==0)
                sieve[j]=i;
    }
}
long long dp[10000002];
int main()
{
    ios_base::sync_with_stdio(false);
    int n=10000000;
    precomp(n);
    int i;
    for(i=2;i<=n;i++)
        dp[i]=dp[i-1]+((sieve[i]!=0)?sieve[i]:i);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<< "\n";
    }

    return 0;
}
