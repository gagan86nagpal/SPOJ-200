#include <iostream>
#include <cmath>
using namespace std;
int a[12];
int main()
{
    int n=10;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans = a[0];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(abs(sum-100) <= abs(ans-100))
           ans = sum;
    }
    cout<<ans<<"\n";
    return 0;
}
