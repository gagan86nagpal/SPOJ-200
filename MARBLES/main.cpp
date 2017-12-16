#include <iostream>

using namespace std;
unsigned long long C(long long n,long long k)
{
    int i;
    k  = min(n-k,k);
    long long ans=1;
    for(i=1;i<=k;i++)
    {
        ans*=(n-i+1);
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
        long long n,k;
        cin>>n>>k;
        long long ans = C(n-1,k-1);
        cout<<ans<<"\n";
    }
    return 0;
}
