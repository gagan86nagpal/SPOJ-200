#include <iostream>

using namespace std;
long long a[1000002];
bool fun(long long h,long long req,long long n)
{
    long long sum=0;
    for(long long i=0;i<n;i++)
        sum+=max(0ll,a[i]-h);
    return (sum>=req);
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,req;
    cin>>n>>req;
    long long i;
    long long l=1,r=1;
    for(i=0;i<n;i++)
        cin>>a[i], r= max((long long)r,a[i]);
    long long m;
    while(l<r)
    {
        m  = (l+r)/2;
        bool eval = fun(m,req,n);
        if(eval)
            l=m+1;
        else
            r=m;
    }
    cout<<l-1<<"\n";

    return 0;
}
