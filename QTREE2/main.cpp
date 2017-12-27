#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define lgn 14
pair <int,int> parent[lgn+1][10003];
vector < pair <int,int> > adj[10003];
int level[10003];
void dfs(int s,int p,int l=0)
{
    level[s]=l;
    for(pair <int,int> node: adj[s])
    {
        if(p==node.first)
            continue;
        parent[0][node.first]={s,node.second};
        dfs(node.first,s,l+1);
    }
}

pair <int,int> lca(int a,int b)
{
    if(level[b]>level[a])
        swap(b,a);
    // a is lower
    int d = level[a]-level[b];
    int cost =0;
    for(int i= lgn;i>=0;i--)
        if( ((d>>i)&1 ) >0 )
            cost+=parent[i][a].second,a=parent[i][a].first;
    // a and b at same level
    if(a==b)
        return {a,cost};
    for(int i=lgn;i>=0;i--)
    {
        if(parent[i][a].first!=parent[i][b].first)
        {
            cost+=parent[i][a].second + parent[i][b].second;
            a=parent[i][a].first;
            b=parent[i][b].first;
        }
    }
    return {parent[0][a].first,cost+parent[0][a].second+parent[0][b].second};
}
void buildLca(int n)
{
    int i;
    for(i=1;i<=lgn;i++)
        for(int j=1;j<=n;j++)
        {
            int p1 = parent[i-1][j].first;
            parent[i][j]={ parent[i-1][p1].first,parent[i-1][j].second + parent[i-1][p1].second};
        }
}

int kancestor(int a,int k)
{
    int i;
    for(i=lgn;i>=0;i--)
        if(((k>>i)&1)>0 )
            a = parent[i][a].first;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=1;i<=n;i++)
            adj[i].clear(),level[i]=0;
        for(i=0;i<n-1;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        parent[0][1]={1,0};
        dfs(1,1);
        buildLca(n);
        string s;
        while(true)
        {
            cin>>s;
            if(s[1]=='O')
                break;
            if(s[0]=='D') // dist
            {
                int a,b;
                cin>>a>>b;
                pair <int,int> l = lca(a,b);
                cout<<l.second<<"\n";
            }
            else // kth
            {
                int a,b,k;
                cin>>a>>b>>k;
                int l = lca(a,b).first;
                int ans;
                int d = level[a]-level[l]+1;
                if(d >=k)
                    ans = kancestor(a,k-1);
                else
                    ans = kancestor(b,level[b]-level[l]- k+d);
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
