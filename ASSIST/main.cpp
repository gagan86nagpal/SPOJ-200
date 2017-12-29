#include <iostream>
using namespace std;
int sieve[1000002];
void mark(int n)
{
    int i=2;
    while(i<=n)
    {
        if(sieve[i]==1)
        {
            i++;
            continue;
        }
        int j=i+1;
        int pos=1;
        while(j<=n)
        {
            if(sieve[j]==0)
            {
                if(pos%i==0)
                    sieve[j]=1;
                pos++;
            }
            j++;
        }
        i++;
    }

}
int a[4000];
int main()
{
    ios_base::sync_with_stdio(false);
    int n=35000;
    mark(n);
    int i;
    int pos=0;
    for(i=2;i<=n;i++)
    {
        if(sieve[i]==0)
        {
            pos++;
            a[pos]=i;
        }
    }
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        cout<<a[n]<<"\n";
    }
    return 0;
}
