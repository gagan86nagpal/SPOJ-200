#include <iostream>

using namespace std;
string a,b;

string dp[102][102];
string solve(int i,int j,int n,int m)
    {
    if(i==n)
        return b.substr(j);
    if(j==m)
        return a.substr(i);
    string s1,s2;
    if(dp[i][j]!="-1")
        return dp[i][j];
    if(a[i]==b[j])
    {
       s1 = a[i] + solve(i+1,j+1,n,m);
       return dp[i][j]= s1;
   }
    s1 =a[i]+ solve(i+1,j,n,m);
    s2 = b[j]+solve(i,j+1,n,m);
    if(s1.size()>s2.size())
        return dp[i][j]=s2;
    else
        return dp[i][j]=s1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    while(cin>>a)
    {
        cin>>b;
        int n =a.size();
        int m =b.size();
        int i,j;
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                dp[i][j]="-1";
        string ans= solve(0,0,n,m);
        cout<<ans<<"\n";
    }
    return 0;
}
