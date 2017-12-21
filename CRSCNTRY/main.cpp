#include <iostream>

using namespace std;
int a[2002],b[2002];
int dp[2002][2002];
int lis(int i,int j,int n,int m)
{
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i==n || j==m)
        return dp[i][j]=0;
    if(a[i]==b[j])
        return dp[i][j]=1+lis(i+1,j+1,n,m);
    return dp[i][j]= max(lis(i+1,j,n,m),lis(i,j+1,n,m));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int d;
    cin>>d;
    while(d--)
    {
        int n=0,m=0;
        while(true)
        {
            cin>>a[n];
            if(a[n]==0)
                break;
            n++;
        }
        int ans =0;
        while(true)
        {
            m=0;
            while(true)
            {
                cin>>b[m];
                if(b[m]==0)
                    break;
                m++;
            }
            if(m==0)
                break;
            int i,j;
            for(i=0;i<=n;i++)
                for(j=0;j<=m;j++)
                    dp[i][j]=-1;
            int val = lis(0,0,n,m);
            ans = max(ans,val);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
