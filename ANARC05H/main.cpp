#include <iostream>

using namespace std;
#define inf 225
int dp[26][inf+1][inf+1];
void print(int a,int b,int c)
{
    int i,j,k;
    for(i=0;i<=a;i++)
    {
        cout<<i<<"\n";
        for(j=0;j<=b;j++)
        {
            for(k=0;k<=c;k++)
            {
                cout<<dp[i][j][k]<<" ";
                cout<<"("<<i<<","<<j<<","<<k<<") ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void solve(string s,int ms)
{
    int n = s.size();
    dp[n-1][s[n-1]-'0'][ms]=1;
   // print(n-1,ms,ms);
    for(int i=n-2;i>=0;i--)
    {
        int digit = s[i]-'0';
        for(int diff=digit;diff<=ms;diff++)
            for(int j=0;j<=ms-diff;j++)
                dp[i][j+digit][j+diff]+= dp[i+1][j][j+diff];   // adding digit to first group
        for(int j=digit ; j<=ms;j++)
            for(int k=j;k<=ms;k++)
                dp[i][digit][j]+=dp[i+1][j][k];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    int tc=0;
    while(true)
    {
        tc++;
        string s;
        cin>>s;
        if(s[0]=='b')
            break;
        int sum=0;
        for(char c:s)
            sum+=c-'0';
        int i,j,k;
        int n = s.size();
        for(i=0;i<=n;i++)
            for(j=0;j<=sum+1;j++)
                for(k=0;k<=sum+1;k++)
                    dp[i][j][k]=0;
        solve(s,sum);
        long long int ans=0;
        for(j=0;j<=sum;j++)
            for(k=j;k<=sum;k++)
                ans+=dp[0][j][k];
         cout<<tc<<". ";
        cout<<ans<<"\n";
    }
    return 0;
}
