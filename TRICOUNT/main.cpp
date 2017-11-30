#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
       // long long ans = (n*(n-1)*(2*n-1) )/6    - (n*(n-1) )/2 +n-1 +n*n;
        long long ans ;
        n++;
        if(n%2==0)
            n/=2,ans= n*(n-1)*(2*n-1) + (5*n*(n-1))/2 + n ;
        else
            n/=2,ans = n*(n-1)*(2*n-1) + (11*n*(n-1) )/2 + 5*n;
        cout<<ans<<"\n";
    }
    return 0;
}
