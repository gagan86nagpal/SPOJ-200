#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getNext[30002];
int h[1000002]; // hash array
int a[30002];
int ans[200003];
int bit[30005];

void update(int i,int val,int n)
{
    while(i<=n)
        bit[i]+=val,i+=(i&-i);
}
int query(int i,int n)
{
    int ans=0;
    while(i>0)
        ans+=bit[i],i-=(i&-i);
    return ans;
}

vector < pair < pair <int,int> ,int> > queries;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {

        if(h[a[i]]!=0) // we have previous occurrence
            getNext[h[a[i]]] = i;
        else  // first occurrence
            update(i,1,n);

        h[a[i]]=i;
    }
    for(i=1;i<=n;i++)
        if(getNext[i]==0) // last elements
            getNext[i]=n+1; // to maintain loop invariant
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        queries.push_back({{l,r},i});
    }
    sort(queries.begin(),queries.end());
    // Sorted l wise;
    int pl= 1;
    for(pair < pair <int,int > ,int > p :queries)
    {
        int l = p.first.first;
        int r = p.first.second;
        int in = p.second;
        while(pl<l)
        {
            update(pl,-1,n); // remove this occurrence
            update(getNext[pl],1,n); // add the next occurence(if it is last , then add it to n+1 index which won't be included in BIT)
            pl++;
        }
        // we have updated now, query
        int temp = query(r,n);
        ans[in]=temp;
    }
    for(i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
