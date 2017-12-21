#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        string c;
        cin>>a>>b>>c;
        long long ans = a*a-2*b;
        cout<<ans<<"\n";
    }
    return 0;
}
