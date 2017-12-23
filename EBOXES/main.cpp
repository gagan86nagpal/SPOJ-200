#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,_,f;
        cin>>n>>k>>_>>f;
        long long ans  = n + (k*(f-n) )/(k-1);
        cout<<ans<<"\n";
    }
    return 0;
}
