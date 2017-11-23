#include <iostream>

using namespace std;
long long powMod(long long a,long long b,long long mod)
{
    long long int ret=1;
    while(b>0)
    {
        if(b%2==1)
            ret*=a;
        a*=a;
        b/=2;
        a%=mod;
        ret%=mod;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long a,b;
        cin>>a>>b;
        long long ans=powMod(a,b,10);
        cout<<ans<<"\n";
    }
    return 0;
}
