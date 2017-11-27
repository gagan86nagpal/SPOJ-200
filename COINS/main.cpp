#include <iostream>
#include <map>
using namespace std;
map < long long ,long long> m;
long long solve(long long  n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(m.find(n)==m.end())
        return m[n]=max(n,solve(n/2) + solve(n/3) + solve(n/4));
    else
        return m[n];
}
int  main()
{
    long long  n;
    while(cin>>n)
    {
        long long ans = solve(n);
        cout<<ans<<"\n";
    }
    return 0;
}
