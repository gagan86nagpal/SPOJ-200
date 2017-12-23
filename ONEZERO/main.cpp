#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
pair <int,int> m[20003];
void bfs(long long n) // generates a string of length k
{
    queue<long long> q;
    q.push(1);
    m[1]={1,-1};
    while(!q.empty())
    {
        long long x =q.front();
        q.pop();
        if(x%n==0)
            return;
        int rem = (x*10)%n;
        if(m[rem].first==-1) // not found
            q.push(rem),m[rem]={x,'0'};
        rem =(x*10 +1)%n;
        if(m[rem].first==-1)
        q.push(rem),m[rem]={x,'1'};
    }
}
string gen()
{
    string ans="";
    int n=0;
    while(n!=1)
    {
        ans.push_back(m[n].second);
        n=m[n].first;
    }
    ans.push_back('1');
    reverse(ans.begin(),ans.end());
    return ans;
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
        if(n==1)
        {
            cout<<1<<"\n";
            continue;
        }
        for(int i=0;i<=n;i++)
            m[i]={-1,-1};
        bfs(n);
        string ans =gen();
        cout<<ans<<"\n";
    }
    return 0;
}
