#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,pair <int,int > > pp;
#define lgn 15
vector< pp > adj[10102];  // holds the tree as well as the edge to vertex mapping also and cost of edge
int subtree[10102];
int segtree[60604];   // segment tree is built on baseArray
int baseArray[10102]; // given ptr of a node,tells us cost and segtree is built on it.
int posInBase[10102];  // this will act as a map from the input vertex to our vertex(in segtree)
int parent[lgn+1][10102]; // LCA DS
int level[10102];  // FOR LCA
int chainHead[10102]; // given a chain number , tells the head
int chainPos[10102];  // Given a normal vertex, it tells the chain it belongs to
int edgeToVertex[10102]; //  (specific to this problem)
int cost[10102];  // give a vertex , tells the cost(actually the edge cost but we have mapped onto vertex)
int chainNo;
int ptr;   // this will give original vertex a new vertex according to chains and segtree
int dfs(int s,int p,int l=0)
{
    parent[0][s]=p;
    subtree[s]+=1;
    level[s]=l;
    for(pp node: adj[s])
    {
        if(node.second.first==p)
            continue;
        cost[node.second.first]=node.first;
        edgeToVertex[node.second.second]=node.second.first;
       subtree[s]+= dfs(node.second.first,s,l+1);
    }
    return subtree[s];
}
void print(int x[],int n,string s)
{
    cout<<s<<"\n";
    int i;
    for(i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<"\n";
}
void printDFS(int n)
{
    print(parent[0],n,"parent:");
    print(subtree,n,"subtree:");
    print(level,n,"level:");
    print(cost,n,"cost");
    print(edgeToVertex,n,"Edge to vertex");
}
// normal lca
int lca(int a,int b)
{
    if(a==b)
        return a;
    if(level[b]>level[a])
        swap(a,b);
    // a is lower , make it level with b
    int d = level[a]-level[b];
    // make a jump to d level
    int i=0;
    while(d>0)
    {
        if(d&1)
            a=parent[i][a];
        i++;
        d/=2;
    }
    if(a==b)
        return a;
    // a and b are level
    // find the min level upto which they are equal
    d = lgn;
    while(d>=0&&parent[d][a]==parent[d][b])
        d--;
    // now go up , such that we are 1 below lca
    for(i=d;i>=0;i--)
    {
        if(parent[i][a]!=parent[i][b])
        {
            a= parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}
// decomposes our tree into chains and stuff
void printHLD(int n)
{
    print(chainHead,n,"Chain Head");
    print(posInBase,n,"posInbase");
    print(chainPos,n,"Chain pos");
    print(baseArray,n,"Base Array");
}
void HLD(int s,int p)
{
    if(chainHead[chainNo]==0) // New Chain
    {
        chainHead[chainNo]=s;
    }
    posInBase[s]=ptr++;   // Here we are assigning vertex to their segtree vertex equivalent
    baseArray[ptr-1]=cost[s]; // Also , our base array is getting ready so that segtree could be built on it
    chainPos[s]=chainNo;
    int specialChild=0;
    for(pp node: adj[s])
    {
        if(node.second.first==p)
            continue;
        if(specialChild==0 ||  subtree[specialChild]<subtree[node.second.first])
            specialChild =node.second.first;
    }
    if(specialChild!=0)  // We should extend this chain
        HLD(specialChild,s);
    // Do HLD on other children
    // In our , we should not call HLD again on parent ,and special child
    for(pp node: adj[s])
    {
        if(node.second.first==p || node.second.first==specialChild)
            continue;
        chainNo++; // THis will be new chain
        HLD(node.second.first,s);
    }

}
void build(int node,int l,int r)
{
    if(l==r)
    {
        segtree[node]=baseArray[l];
        return;
    }
    int m =(l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    segtree[node]  = max(segtree[2*node],segtree[2*node+1]);
}
int query(int node,int l,int r,int ql,int qr)
{
    if(qr< l || ql>r)
        return -1;
    if(ql<=l&& qr>=r)
        return segtree[node];
    int m = (l+r)/2;
    int a= query(2*node,l,m,ql,qr);
    int b = query(2*node+1,m+1,r,ql,qr);
    return max(a,b);
}
void update(int node,int l,int r,int i,int x)
{
    if(l==r)
    {
        baseArray[i]= segtree[node]=x;
        return;
    }
    int m = (l+r)/2;
    if(i<=m)
        update(2*node,l,m,i,x);
    else
        update(2*node+1,m+1,r,i,x);
    segtree[node]  = max(segtree[2*node],segtree[2*node+1]);
}
void buildLCA(int n)
{
    int i,j;
    for(j=1;j<lgn;j++)
    {
        for(i=1;i<=n;i++)
        {
            int x = parent[j-1][i];
            parent[j][i ] = parent[j-1][x];
        }
    }
}
// b must be some ancestor of a
// return ,max cost vertex from up till b , not including b
int queryUp(int a,int b)
{
    int chaina;
    int ans=0;
    int chainb = chainPos[b];
    while(true) // make segtree query and climb through a light edge and recursive call
    {
        chaina = chainPos[a];
        if(chaina==chainb)
            break;

        int chainh = chainHead[chaina];
        ans= max(query(1,1,ptr-1,posInBase[chainh],posInBase[a]),ans);
        a = parent[0][chainh];
    }
    // they belong to same chain
    if(a==b)
        return ans;
    // a is behind the b
    // just make segtree call
    return max(query(1,1,ptr-1,posInBase[b]+1,posInBase[a]),ans);
}
int solve(int a,int b) // this is somewhat complex
{
    int l = lca(a,b);
    int s1 = queryUp(a,l);
    int s2 = queryUp(b,l);
    return max(s1,s2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        int root = 1; // since tree is undirected and we just intrested in finding the distance between two vertices
        // We can treat any vertex as root.
        int n;
        cin>>n;
        int i;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            subtree[i]=baseArray[i]=posInBase[i]=parent[0][i]=level[i]=chainHead[i]=chainPos[i]=0;
            edgeToVertex[i]=cost[i]=0;
        }
        chainNo = ptr=1;
        for(i=1;i<=n-1;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({c,{b,i}});
            adj[b].push_back({c,{a,i}});
        }
        dfs(root,0);
        buildLCA(n);
        HLD(1,0);
      //  printHLD(n);
        build(1,1,ptr-1);
        while(cin>>s)
        {
            if(s[0]=='D')
                break;
            if(s[0]=='Q') // query
            {
                int a,b;
                cin>>a>>b;
                int ans =solve(a,b);
                cout<<ans<<"\n";
            }
            else // change
            {
                int edge,val;
                cin>>edge>>val;
                int u = edgeToVertex[edge]; // give me vertex please
                u = posInBase[u]; // give me segtree vertex please
                update(1,1,ptr-1,u,val) ; // ptr-1 is the size of segtree
            }
        }
    }
    return 0;
}
