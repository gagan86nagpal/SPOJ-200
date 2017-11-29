#include <iostream>
#include <vector>
using namespace std;


int id[10002];
int root(int i)
{
    if(i!=id[i])
        return id[i]=root(id[i]);
    return i;
}
void unite(int a,int b)
{
    a = root(a);
    b = root(b);
    id[a]=b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        id[i]=i;
    bool flag = true;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(root(a)==root(b))
            flag=false;
        else
            unite(a,b);
    }
    if(m==n-1 && flag)
        cout<<"YES\n";

    else
        cout<<"NO\n";
    return 0;
}
