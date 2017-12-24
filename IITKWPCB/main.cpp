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
        long long ans  = n/2;
        if(n%4==0)
            ans--;
        else if(n%4==2)
            ans-=2;
        if(n<=2)
            ans=n-1;
        cout<<ans<<"\n";
    }
    return 0;
}
