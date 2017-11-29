#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i=0;
        i = (1+sqrt(2*n-1) )/2;
        int sum=i*i + (i+1)*(i+1);
        int prev = sum-i*4;
        int k;
        cout<<"TERM "<<n<<" IS ";
        if(prev +i-1 >= n)
        {
            k = prev+i-1-n;
            cout<< k+1<<"/"<<2*i-k-1<<"\n";
        }
        else if(sum-i<=n)
        {
            k= n-sum+i;
            cout<< 2*i-k+1<<"/"<<k+1<<"\n";
        }
        else
        {
            k=n-(prev+i);
            cout<< k+1<<"/"<<2*i-k<<"\n";
        }
    }
    return 0;
}
