#include <iostream>

using namespace std;
long long powmod(long long a,long long b,long long p)
{
    if(b==0)
        return 1;
    long long c = powmod(a,b/2,p);
    if(b%2==0) // even
        return (c*c)%p;
    // odd
    return (c*c*a)%p;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        long long b;
        cin>>a>>b;
        long long ans = powmod(a[a.size()-1]-'0',b,10);
        cout<<ans<<"\n";
    }
    return 0;
}
