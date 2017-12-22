#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.141592653589
#define e 2.71828182845904
int main()
{
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        double lg=0;
        if(n<=2)
        {
            cout<<1<<"\n";
            continue;
        }
        lg = n*log10(n/e) + log10(2*pi*n)/2.0;
        cout<<1 + (long long int)lg <<"\n";
    }
    return 0;
}
