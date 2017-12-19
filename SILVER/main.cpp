#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        int ans = log2(n);
        cout<<ans<<"\n";
    }
    return 0;
}
