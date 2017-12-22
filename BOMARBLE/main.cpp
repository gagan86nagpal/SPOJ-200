#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        n++;
        int ans = 3*n*n -n;
        ans/=2;
        cout<<ans<<"\n";
    }
    return 0;
}
