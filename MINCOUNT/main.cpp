#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long ans;

        if(n<=1)
            ans=0;
        else
        {
            int d = n%3;
            n=(n+1)/3,ans=(3*n*n-n)/2;
            if(d==0)
                ans+=n;
            else if(d==1)
                ans+=2*n;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
