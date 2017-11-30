#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    while(true)
    {
        int l;
        cin>>l;
        if(l==0)
            break;
        double ans = (l*l)/(6.28318);
        cout<<setprecision(2)<<fixed<<ans<<"\n";
    }
    return 0;
}
