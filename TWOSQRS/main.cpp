#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long a =0;
        long long b = sqrt(n)+1;
        bool flag = false;
        while(a<=b)
        {
            long long c = a*a + b*b;
            if(c ==n)
            {
                flag  = true;
                break;
            }
            else if (c>n)
                b--;
            else
                a++;
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
