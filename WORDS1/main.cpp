#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int in[27],out[27],isVertex[27],vis[27];
vector <int> adj[27];

void dfs(int s,int p)
{
    vis[s]=1;
    for(int node:adj[s])
    {
        if(!vis[node])
            dfs(node,s);
    }
}
bool isConnected()
{
    int i;
    for(i=0;i<26;i++)
    {
        if(isVertex[i])
        {
            dfs(i,-1);
            break;
        }
    }
    for(i=0;i<26;i++)
        if(isVertex[i] && vis[i]==0)
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=26;i++)
        {
            adj[i].clear();
            out[i]=in[i]=vis[i]=isVertex[i]=0;
        }
        int n;
        cin>>n;
        string s;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>s;
            int a= s[0]-'a';
            int b= s[s.size()-1]-'a';
            adj[a].push_back(b);
            out[a]++;
            in[b]++;
            isVertex[a]=isVertex[b]=1;
            adj[b].push_back(a);
        }
        int x=0;
        bool cond1=true;
        for(i=0;i<26;i++)
        {
            if(!isVertex[i])
                continue;
            if(abs(in[i]-out[i])==1)
                x++;
            else if(in[i]!=out[i])
                cond1=false;
        }
        if(!(x==0 || x==2))
            cond1=false;
        if(cond1 && isConnected())
            cout<<"Ordering is possible.\n";
        else
            cout<<"The door cannot be opened.\n";
    }
    return 0;
}
