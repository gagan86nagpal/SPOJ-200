#include <iostream>

using namespace std;
long long C(long long n,long long r)
{
    r = min(r,n-r);
    int i;
    long long ans=1ll;
    for(i=1;i<=r;i++)
    {
        ans*= n-i+1;
        ans/=i;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,ans;
        cin>>a>>b;
        ans = C(9+b,b);
        cout<<a<<" "<<ans<<"\n";
    }
    return 0;
}
