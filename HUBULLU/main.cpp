#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        int p;
        cin>>n>>p;
        cout<<( (p==0)?"Airborne ":"Pagfloyd ")<<"wins.\n";
    }
    return 0;
}
