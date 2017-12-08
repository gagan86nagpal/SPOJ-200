#include <iostream>

using namespace std;
int seive[1000002];
int etf[1000002];
int main()
{
    int i,j;
    for(i=2;i*i<=1000000;i++)
    {
        for(j=i*i;j<=1000000;j+=i)
            if(seive[j]==0)
                seive[j]=i;
    }
    etf[1]=1;
    for(i=2;i<=1000000;i++)
    {
        if(seive[i]==0) // prime
            etf[i]=i-1;
        else
        {
            j=i;
            int d= seive[j];
            while(j%d==0)
                j/=d;
            if(j==1) // prime power
                etf[i]=i - i/seive[i];
            else // break into two co primes and use property
                etf[i]= etf[j]*etf[i/j]; // j and i/j are co prime
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<etf[n]<<"\n";
    }
    return 0;
}
