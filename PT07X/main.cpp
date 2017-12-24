#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int > adj[100003];

int dp[100002];
int solve(int s,int p)
{
    if(dp[s]!=-1)
        return dp[s];
    if(adj[s].size()==1 && adj[s][0]==p) // leaf
        return dp[s]=0;
    int ans1=0,ans2=0;
    int nc=0;
    for(int c: adj[s])
    {
        if(c==p)
            continue;
        nc++;
        ans2+=solve(c,s);  // taking children
        for(int cc: adj[c])
        {
            if(cc==s)
                continue;
            ans1+=solve(cc,c);  // taking root and grand childs
        }
    }

    return dp[s]=min(ans1+nc,1+ans2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=1;i<=n;i++)
        dp[i]=-1;
    int root=1;
   int ans = solve(root,-1);
   cout<<ans<<"\n";
    return 0;
}
