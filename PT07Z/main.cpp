#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector <int> tree[10001];
pair <int,int> ret;
void dfs(int s,int p,int d=0)  // node,dist
{
    if(ret.second < d)
        ret={s,d};
    for(int node: tree[s])
    {
        if(node==p)
            continue;
        dfs(node,s,d+1);
    }
}
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ret ={-1,0};
    dfs(1,-1);
    int u = ret.first;
    dfs(u,-1);
    int d =ret.second;
    cout<<d<<"\n";
    return 0;
}
