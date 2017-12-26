#include <iostream>
#include <set>
using namespace std;
int parent[100003];

int root(int i)
{
    if(i!=parent[i])
        return parent[i]= root(parent[i]);
    return i;
}
void unite(int a,int b)
{
    a = root(a);
    b = root(b);
    if(a!=b)
    parent[a]=b;
}
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        s.clear();
        int n,e;
        int i;
        cin>>n>>e;
        for(i=0;i<=n;i++)
            parent[i]=i;
        for(i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        for(i=0;i<n;i++)
            s.insert(root(i));
            cout<<s.size()<<"\n";
    }
    return 0;
}
