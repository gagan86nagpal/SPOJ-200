#include <iostream>

using namespace std;
long long mod =10000007;

long long powMod(long long a,long long b)
{
    if(b==0)
        return 1;
    if(b%2==0)
    {
        long long c =powMod(a,b/2);
        return (c*c)%mod;
    }
    else
    {
        long long c = powMod(a,b/2);
        return ((a*c)%mod *c)%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    while(true)
    {
        long long n,k;
        cin>>n>>k;
        if(n==0 && k==0)
            break;
        long long ans = 2*powMod(n-1,k)  + powMod(n,k) + 2*powMod(n-1,n-1) +powMod(n,n)  ;
        ans%=mod;
        cout<<ans<<"\n";
    }
    return 0;
}
