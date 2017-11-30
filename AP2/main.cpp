#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y,z,a,n,d;
        cin>>x>>y>>z;
        n = (2*z)/(y+x);
        d = (y-x)/(n-5);
        a = x-2*d;
        cout<<n<<"\n";
        for(int i=0;i<n;i++)
            cout<<a+i*d<<" ";
        cout<<"\n";
    }

    return 0;
}
