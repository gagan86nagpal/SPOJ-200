#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <stdlib.h>
using namespace std;
int n=100000;
int vis[100002];
int prime[100002];
void seive()
{
    int i,j;
    for(i=2;i*i<=n;i++)
    {
        for(j=i*i;j<=n;j+=i)
            prime[j]=1;
    }
}

int bfs(int a,int b)
{
    queue < pair <int,int > > q;
    vector<int> v;
    vector<int> init;
    q.push({a,0});
    vis[a]=1;

    while(!q.empty())
    {

        pair<int,int> p = q.front();
        q.pop();
        int n = p.first;
        int level = p.second;
      //  cout<<n<<" "<<level<<"\n";
        if(n==b)
            return level;
        v.clear();
         while(n>0)
        {
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        init=v;
        for(int i=0;i<v.size();i++)
        {
            v=init;
            for(int j=0;j<10;j++)
            {
                if(i==0 && j==0)
                    continue;
                v[i]=j;
                int m = v[3] +v[2]*10 + v[1]*100 + v[0]*1000;
                if(prime[m]==0 && vis[m]==0) // prime
                    vis[m]=1,q.push({m,level+1});
            }
        }
    }
    return -1;
}
int main()
{
    seive();
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;
        for(int i=0;i<100000;i++)
            vis[i]=0;
        int ans= bfs(a,b);
        if(ans==-1)
            cout<<"Impossible\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}
