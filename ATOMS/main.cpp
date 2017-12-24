#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long  n,k,m;
        cin>>n>>k>>m;
        if(n>=m)
        {
            cout<<0<<"\n";
        }
        else
        {
            int ans = log(m/n)/log(k);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
