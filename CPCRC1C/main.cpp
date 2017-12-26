#include <iostream>
#include <algorithm>
using namespace std;
long long p[16];
long long dp[10][12];
long long solve(long long n,long long d)
{
    if(dp[n][d]!=-1)
        return dp[n][d];
    if(n==0)
        return 0;
    if(d==0)
        return dp[n][d]=(n*(n+1) )/2;
    if(n==1)
        return dp[n][d]=solve(9,d-1)  + 9*(p[d-1]-1) + solve(1,d-1);
    return dp[n][d]=solve(n-1,d)  + (n-1)*(p[d]) + solve(1,d);
}
long long stringtoi(string n)
{
    long long ret=0;
    for(char c:n)
    {
        ret=ret*10 + c-'0';
    }
    return ret;
}
long long ans(string n)
{
    if(n=="")
        return 0;
    long long one = n[0] -'0';
    long long s1=solve(one,n.size()-1);
    string x = n.substr(1);
    long long s2= one*stringtoi(x);
    return s1+s2 + ans(x);
}

string integertos(long long n)
{
    string ret ="";
    while(n>0)
    {
        ret.push_back(n%10+ '0');
        n/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    long long i,j;
    for(i=0;i<=9;i++)
        for(j=0;j<=10;j++)
            dp[i][j]=-1;
    p[0]=1;
    for(i=1;i<=10;i++)
        p[i]=p[i-1]*10;
    while(true)
    {
        string a,b;
        int c;
        cin>>c>>b;
        if(c==-1 && b=="-1")
            break;
        c--;
        a = integertos(c);
        long long x = ans(b) - ans(a);
        cout<<x<<"\n";
    }
    return 0;
}
