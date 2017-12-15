#include <iostream>
#include <vector>
using namespace std;
int color[2002];
vector<int> graph[2002];
bool dfs(int s,int parent)
{
    bool flag = true;
    for(int node: graph[s])
    {
        if(color[node]==color[s])
            return false;
        else if(color[node]!=0) // already visited
            continue;
        color[node]=3-color[s]; // assign color
        flag = flag & dfs(node,s);
    }
    return flag;
}
int main()
{
    int t;
    int tc=0;
    cin>>t;
    while(t--)
    {
        tc++;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            color[i]=0,graph[i].clear();
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool flag;
        for(int i=1;i<=n;i++)
        {
            if(color[i]!=0)
                continue;
            color[i]=1;
            flag = dfs(i,-1);
            if(!flag)
                break;
        }
        cout<<"Scenario #"<<tc<<":\n";
        if(flag)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }
    return 0;
}
