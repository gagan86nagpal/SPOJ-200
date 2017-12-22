#include <iostream>

using namespace std;
long long a[10002],b[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        b[n-1]=a[n-1];
        for(i=n-2;i>=0;i--)
        {
            b[i]=b[i+1]+a[i];
        }
        long long ans=0;
        for(i=0;i<n-1;i++)
            ans+=b[i+1]-a[i]*(n-1-i);
        cout<<ans<<"\n";
    }
    return 0;
}
