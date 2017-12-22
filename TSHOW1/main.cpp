#include <iostream>

using namespace std;
long long getpow2(long long n)
{
    long long ret=1;
    while(ret<=n)
        ret<<=1;
    return ret/2;
}
string  gen(long long n)
{
    if(n==2)
        return "5";
    if(n==3)
        return "6";
    long long p,pp;
    p = getpow2(n);
    pp=p/2;
    if(pp+p > n)
        return "5"+gen(n-pp);
    else
        return "6"+gen(n-p);
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout<<gen(n+1)<<"\n";
    }
    return 0;
}
