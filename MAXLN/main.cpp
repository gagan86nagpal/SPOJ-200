#include <iostream>

using namespace std;

int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        long long r;
        cin>>r;
        cout<<"Case "<<i<<": "<<4ll*r*r<<".25\n";
    }
    return 0;
}
