#include <iostream>
#include <algorithm>
using namespace std;

int a[100002];
int b[100002];
int main()
{
    while(true)
    {
        int n;
        long long ans=0;
        cin>>n;
        if(n==0)
            break;
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        for(i=0;i<n;i++)
        {
            ans+=  (long long)a[i]*b[n-i-1];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
