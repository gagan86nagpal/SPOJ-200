#include <iostream>
#include <stdio.h>
using namespace std;
int factor[1000002];

void seive(int n)
{
    int i,j;
    for(i=2;i*i<=n;i++)
    {
        for(j=2*i;j<=n;j+=i)
        {
            if(factor[j]==0)
                factor[j]=i;
        }
    }
    for(i=1;i<=n;i++)
        if(factor[i]==0)
            factor[i]=i;
}

int divisors(int n)
{
    int ans =1;
    while(n>1)
    {
        int d =factor[n];
        int cnt=1;
        while(n%d==0)
            n/=d,cnt++;
        ans*=cnt;
    }
    return ans;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    seive(1000001);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,g;
        scanf("%d %d",&a,&b);
        g = gcd(a,b);
        int ans =divisors(g);
        printf("%d\n",ans);
    }

    return 0;
}
