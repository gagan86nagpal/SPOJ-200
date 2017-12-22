#include <iostream>
#include <algorithm>
using namespace std;
int a[2003];
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int j;
        int ans=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                ans+= (a-upper_bound(a,a+n,a[i]+a[j]) +n);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
