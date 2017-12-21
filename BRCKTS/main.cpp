#include <iostream>
#include <utility>
using namespace std;

pair <int,int> segtree[120002];
string s;
void build(int node,int l,int r)
{
    if(l==r)
    {
        if(s[l-1]=='(')
            segtree[node]={1,0};
        else
            segtree[node]={0,1};
        return ;
    }
    int m =(l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    pair <int,int>  p1 = segtree[2*node];
    pair <int,int> p2 =segtree[2*node+1];
    int match = min(p1.first,p2.second);
    segtree[node] = {p2.first+p1.first -match  , p1.second + p2.second -match};
}
void update(int node,int l,int r,int i)
{
    if(l==r)
    {
        if(s[l-1]=='(')
            s[l-1]=')';
        else
            s[l-1]='(';
        if(s[l-1]=='(')
            segtree[node]={1,0};
        else
            segtree[node]={0,1};
        return ;
    }
    int m = (l+r)/2;
    if(i<=m)
        update(2*node,l,m,i);
    else
        update(2*node+1,m+1,r,i);
    pair <int,int>  p1 = segtree[2*node];
    pair <int,int> p2 =segtree[2*node+1];
    int match = min(p1.first,p2.second);
    segtree[node] = {p2.first+p1.first -match  , p1.second + p2.second -match};

}
int main()
{
    ios_base::sync_with_stdio(false);
    int t=10;
    int tc=0;
    while(t--)
    {
        tc++;
        cout<<"Test "<<tc<<":\n";
        int n;
        cin>>n;
        cin>>s;
        build(1,1,n);
        int m;
        cin>>m;
        while(m--)
        {
            int x;
            cin>>x;
            if(x==0)
                if(segtree[1].first==0 && segtree[1].second==0)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            else
                update(1,1,n,x);
        }
    }
    return 0;
}
