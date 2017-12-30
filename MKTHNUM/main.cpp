#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Idea is to form merge sort tree on the indices(sorted by the values as keys)
// Now , If we want to look for k th element in a node in our segtree , we will
// Find how many elements are in left child in our given range query,
// If left child has more then k elements then recursively go in left child looking for K.
// Else go in right child looking for k- #Elements (in range in left child)
// Finding the elements can be done by binary search and is logn at every level of segtree
// Since their are logn levels, hence per query is log^2(n) which should pass

vector < pair <int,int> > a;
vector <int> segtree[400002];
int arr[100003];
void build(int node,int l,int r)
{
    if(l==r)
    {
        segtree[node].push_back({a[l].second});
        return ;
    }
    int m =(l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    merge(segtree[2*node].begin(),segtree[2*node].end(),segtree[2*node+1].begin(),segtree[2*node+1].end(),back_inserter(segtree[node])); // STL ROCKS
}

int query(int node,int l,int r,int ql,int qr,int k)
{
    if(l==r) // k should be 1 here
    {
        return segtree[node][0];
    }
    int elements = upper_bound(segtree[2*node].begin(),segtree[2*node].end(),qr) - lower_bound(segtree[2*node].begin(),segtree[2*node].end(),ql);
    int m = (l+r)/2;
    if(elements >=k) // ans in left
        return query(2*node,l,m,ql,qr,k);
    else
        return query(2*node+1,m+1,r,ql,qr,k-elements);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int i;
    a.push_back({-2000000000,0}); // to make 1 indexing
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[i+1]=x; // to give answers
        a.push_back({x,i+1});  // to build merge sort tree
    }
    sort(a.begin(),a.end());
    build(1,1,n);
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int in = query(1,1,n,l,r,k);
        cout<<arr[in]<<"\n";
    }

    return 0;
}
