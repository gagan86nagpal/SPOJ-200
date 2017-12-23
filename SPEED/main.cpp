#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
        return gcd(b,a%b);
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long a,b,x;
        cin>>a>>b;
        x=abs(a-b);
         cout<<x/gcd(abs(a),abs(b))<<"\n";
    }
    return 0;
}
