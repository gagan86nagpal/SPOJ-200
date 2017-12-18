#include <iostream>
#include <utility>
using namespace std;

typedef pair < pair < long long ,long long > , pair <long long ,long long> > p;
long long mod = 1000000007;
p one ={{1ll,1ll},{1ll,0ll}};
p mul(p p1,p p2)
{
    long long a1 = p1.first.first;
    long long b1  = p1.first.second;
    long long c1 = p1.second.first;
    long long d1  = p1.second.second;
    long long a2 = p2.first.first;
    long long b2  = p2.first.second;
    long long c2 = p2.second.first;
    long long d2  = p2.second.second;
    return {
        { ( (a1*a2)%mod + (b1*c2)%mod )%mod ,((a1*b2)%mod +(b1*d2)%mod)%mod },
        { ((c1*a2)%mod+(d1*c2)%mod)%mod,((c1*b2)%mod+(d1*d2)%mod)%mod}
        };
}
p powMod(p p1,long long b)
{
    if(b==0)
        return one;
    if(b==1)
        return p1;
    if(b%2==0)
        return powMod(mul(p1,p1),b/2);
    p p2=powMod(mul(p1,p1),b/2) ;
    return mul(p2,p1);
}
long long fib(long long n)
{
    if(n==0)
        return 0ll;
    p p1 = powMod(one,n);
    return p1.second.first;
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
      //  long long ans = (fib(r+2) - fib(l+1) + mod)%mod;  // Easy way

      int d = r-l+1;
      long long fd = fib(d);
      long long fd1 = fib(d-1);
      long long fn = fib(l);
      long long fn1 = fib(l+1);
      long long ans = (fd*fn)%mod + ((fd +fd1 -1 + mod)*fn1 )%mod;  //
      ans%=mod;
        cout<<ans<<"\n";
    }
    return 0;
}
