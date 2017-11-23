#include <iostream>
#include <stdlib.h>
using namespace std;
int a[10002];
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        int ans=0;
        if(n==-1)
            break;
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        int sum=0;
        for(i=0;i<n;i++)
            sum+=a[i];
        if(sum%n==0) //possible
        {
            int mean=sum/n;
            for(i=0;i<n;i++)
                ans+=abs(mean-a[i]);
            ans/=2;
        }
        else
        {
            ans=-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
