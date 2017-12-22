#include <iostream>
#include <algorithm>
using namespace std;
long long a[1002],b[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t;
    cin>>t;

    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        n--;
        m--;
        int i,j;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+m);
        i=n-1;
        j=m-1;
        long long ans=0;
        while(i>=0 && j>=0)
        {
            if(a[i]>b[j])
                ans+=a[i--]*(m-j);
            else
                ans+=b[j--]*(n-i);
        }
        while(i>=0)
            ans+=a[i--]*(m-j);
        while(j>=0)
            ans+=b[j--]*(n-i);
        cout<<ans<<"\n";
    }

    return 0;
}
