#include <iostream>
using namespace std;
#define inf 80000000
int ox[1003];
int ni[1003];
int w[1003];
int dp[23][81][1002];
int solve(int oxr, int nir,int i,int n)
{
    if(oxr==0 && nir==0)
        return 0;
    if(dp[oxr][nir][i]!=-1)
        return dp[oxr][nir][i];
    if(i==n)
       return inf;
    int take = w[i]+solve( max(0,oxr-ox[i]),max(0,nir-ni[i]),i+1,n);
    int dont_take= solve(oxr,nir,i+1,n);
    return dp[oxr][nir][i]=min(take,dont_take);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>t;
    while(t--)
    {
        int O,N;
        cin>>O>>N;
        cin>>n;
        int i;
        for(i=0;i<=O;i++)
            for(int j=0;j<=N;j++)
                for(int k=0;k<=n;k++)
                    dp[i][j][k]=-1;
        for(i=0;i<n;i++)
            cin>>ox[i]>>ni[i]>>w[i];
        int ans = solve(O,N,0,n);
        cout<<ans<<"\n";
    }
    return 0;
}
