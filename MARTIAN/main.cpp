#include <iostream>

using namespace std;
int y[502][502],b[502][502];
int dp[502][502];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    int i,j;
    while(true)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>y[i][j],y[i][j]+=y[i][j-1];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>b[i][j],b[i][j]+=b[i-1][j];

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                dp[i][j]= max(dp[i][j-1]+b[i][j],y[i][j]+dp[i-1][j]);
        cout<<dp[n][m]<<"\n";
    }
    return 0;
}
