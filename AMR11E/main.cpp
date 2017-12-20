#include <iostream>
#include <vector>
using namespace std;
int factor[3002];
void sieve(int n)
{
    int i,j;
    for(i=2;i*i<=n;i++)
    {
        for(j=i*2;j<=n;j+=i)
        {
            if(factor[j]==0)
                factor[j]=i;
        }
    }
}
int cnt(int n)
{
    if(factor[n]==n)
        return 1;
    int ret=0;
    while(n>1)
    {
        int d = factor[n];
        if(d==0)
            d=n;
        ret++;
        while(n%d==0)
            n/=d;
    }
    return ret;
}
int ans[2002];
void pre_process()
{
    int n=3000;
    sieve(n);
    int pos=1;
    for(int i=1;i<=n;i++)
    {
        int d= cnt(i);
        if(d>=3)
            ans[pos++]=i;
    }
}
int main()
{
    pre_process();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<"\n";
    }
    return 0;
}
