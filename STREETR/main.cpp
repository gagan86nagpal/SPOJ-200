#include <iostream>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int a[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    int g=0;
    for(i=1;i<n;i++)
    {
        g=gcd(g,a[i]-a[i-1]);
    }
    int ans=0;
    for(i=1;i<n;i++)
    {
        ans+=(a[i]-a[i-1])/g -1;
    }
    cout<<ans<<"\n";
    return 0;
}
