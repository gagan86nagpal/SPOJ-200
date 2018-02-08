#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
vector<int> owner[300002];
ULL BIT[300002];
int req[300002];
vector<pair< pair<int,int> , int> > queries;
int hi[300002],lo[300002];
vector<int> toCheck[300002];
void update(int i,int n,ULL val)
{
    while(i<=n)
        BIT[i]+=val,i+=(i&-i);
}
ULL query(int i)
{
    ULL ans=0;
    while(i>0)
        ans+=BIT[i],i-=(i&-i);
    return ans;
}
void apply(int in,int sz)
{
        int l =queries[in].first.first;
        int r = queries[in].first.second;
        ULL val =queries[in].second;
         if(l <= r)
        {
            update(l,sz,val);
            update(r + 1,sz,-val);
        }
        else
        {
            update(l,sz,val);
            update(1,sz,val);
            update(r+ 1,sz,-val);
        }
}
ULL cnt(int who,int sz,ULL val)
{
    ULL cnt=0;
    for(ULL x:owner[who])
        if(cnt<val)
            cnt+=query(x);
        else
            break;
    return cnt<val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,x;
    for(i=1;i<=m;i++)
        cin>>x,owner[x].push_back(i);
    for(i=1;i<=n;i++)
        cin>>req[i];
    int q;
    cin>>q;
    queries.push_back({{0,0},0});
    for(i=1;i<=q;i++)
    {
        int l,r,v;
        cin>>l>>r>>v;
        queries.push_back({{l,r},v});
    }

    for(i=1;i<=n;i++)
       lo[i]=1,hi[i]=q+1;
    bool changed=true;
    while(changed)
    {
        for(i=1;i<=m;i++)
            BIT[i]=0;
        for(i=1;i<=n;i++)
            if(lo[i]!=hi[i]) // still needs to check
                toCheck[(lo[i]+hi[i])/2].push_back( i );
        changed = false;
        for(i=1;i<=q;i++)
        {
            apply(i,m);
            for(ULL in : toCheck[i])
            {
                changed = true;
                if(cnt(in,m,req[in]))
                    lo[in]=i+1;
                else
                    hi[in]=i;
            }
            toCheck[i].clear();
        }

    }
    for(i=1;i<=n;i++)
    {
        assert(lo[i]==hi[i]);
        if(lo[i]==q+1)
            cout<<"NIE\n";
        else
            cout<<lo[i]<<"\n";
    }
    return 0;
}
