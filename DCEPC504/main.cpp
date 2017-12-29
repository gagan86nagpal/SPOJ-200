#include <iostream>

using namespace std;


int solve(long long n,long long k)
{
    if(n==1)
        return 0;
    k++;
    int parity = k&1;
    return parity^solve( n-1,k/2 );
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        int ans = solve(n,k);
        cout<<(ans==0?"Male":"Female")<<"\n";
    }
    return 0;
}
/*
10
2 1
3 2
*/
