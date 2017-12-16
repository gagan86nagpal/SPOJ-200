#include <iostream>

using namespace std;
long long a[1000003];
int main()
{
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s=0,e=0;
    long long sum=a[0];
    long long ans=0;
    while(e<n)
    {
        if(sum>m)
        {
            sum-=a[s];
            s++;
        }
        else
        {
            e++;
            sum+=a[e];
        }
        if(sum<=m)
            ans = max(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}
