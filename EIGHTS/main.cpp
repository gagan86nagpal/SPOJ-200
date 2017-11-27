#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long k;
        cin>>k;
        cout<<192+(k-1)*250<<"\n";
    }
    return 0;
}
