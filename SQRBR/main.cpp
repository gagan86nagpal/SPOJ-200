#include <iostream>

using namespace std;


// I was not able to solve it. Had to look up the solution
// I was not able to come up with the dp states and hence the recurrence
// It is because , till now the DP problems I have solved have well defined
// requirements hence dp states were easy to recognize.
// ALso , i was thinking in terms of bitmask because of the constralong longs
// Here , idea to come up with dp states is amazing , rest is easy

// dp [i][j]  is how many valid ways to fill first i characters , and #( - #) = j
// dp[2*n][0]  is answer
long long a[50];
long long dp[50][50];
long long solve(long long i,long long j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==1 && j==1)
        return dp[i][j]=1;
    if(i==1)
        return dp[i][j]=0;
    if(a[i]==1) // we fix i th paranthesis ,
        return dp[i][j]=solve(i-1,j-1);
    else
        return dp[i][j] = solve(i-1,j-1) + solve(i-1,j+1);
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k,x;
        cin>>n>>k;
        long long i,j;
        for(i=0; i<=2*n; i++)
            for(j=0; j<=n; j++)
                dp[i][j]=-1;
        for(i=0; i<=2*n; i++)
            a[i]=0;
        for(i=0; i<k; i++)
            cin>>x,a[x]=1;
        long long ans =solve(2*n,0);
        cout<<ans<<"\n";
    }
}
