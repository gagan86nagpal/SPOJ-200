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
        long long ans = n*(3*n+1);
        ans/=2;
        ans%=1000007;
        cout<<ans<<"\n";
    }
    return 0;
}
