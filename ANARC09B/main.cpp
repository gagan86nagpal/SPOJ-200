#include <iostream>

using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    while(true)
    {
        long  long a,b;
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        long long g = gcd(a,b);
        cout<<(a*b)/(g*g)<<"\n";
    }
       return 0;
}
