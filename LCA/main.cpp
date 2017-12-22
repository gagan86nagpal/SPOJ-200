#include <iostream>
#include <vector>
using namespace std;
#define lgn  12


vector<int> adj[1002];
int parent[lgn+1][1002];
int level[1002];

void print(int n)
{
    int i,j;
    for(i=0;i<lgn;i++)
    {
        for(j=1;j<=n;j++)
            cout<<parent[i][j]<<" ";
        cout<<"\n";
    }
}
int lca(int a,int b)
{
    if(a==b)
        return a;
    if(level[b]>level[a])
        swap(b,a);
    // a is lower equal to b
    int d= level[a]-level[b];
    int i=0;
    while(d>0)
    {
        if(d&1)
            a = parent[i][a];
        i++;
        d>>=1;
    }
    // a and b are at same level
    if(a==b)
        return a;
    d= lgn;
    while(d>=0 &&parent[d][a]==parent[d][b])
        d--;

    for(i=d;i>=0;i--)
    {
        if(parent[i][a]!=parent[i][b])
        {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}
void dfs(int s,int p,int l=0)
{
    level[s]=l;
    for(int node: adj[s])
        dfs(node,s,l+1);
}
void build(int n)
{
    int i,j;
    for(i=1;i<lgn;i++)
    {
        for(j=1;j<=n;j++)
        {
            int p = parent[i-1][j];
            parent[i][j]=parent[i-1][p];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        tc++;
        cout<<"Case "<<tc<<":"<<"\n";
        int n;
        int i;
        cin>>n;
        for(i=1;i<=n;i++)
            parent[0][i]=0,adj[i].clear();
        for(i=1;i<=n;i++)
        {
            int m;
            cin>>m;
            while(m--)
            {
                int x;
                cin>>x;
                parent[0][x]=i;
                adj[i].push_back(x);
            }
        }
        int root=0;
        for(int i=1;i<=n;i++)
        {
            if(parent[0][i]==0)
            {
                root=i;
                break;
            }
        }
        dfs(root,0);
        build(n);
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            int ans = lca(a,b);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
