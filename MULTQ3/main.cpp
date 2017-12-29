#include <iostream>

using namespace std;
struct block
{
    int mod[3]={0,0,0};
};

block segtree[400002];
int lazy[800002];

void build(int node,int l,int r)
{
    if(l==r)
    {
        segtree[node].mod[0]=1;
        return;
    }
    int m = (l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    block b1 = segtree[2*node];
    block b2 = segtree[2*node+1];
    for(int i=0;i<3;i++)
        segtree[node].mod[i]=b1.mod[i]+b2.mod[i];
}
block query(int node,int l,int r,int ql,int qr)
{
   if(lazy[node]!=0)
    {
        int x= lazy[node];
        lazy[node]=0;
        int temp[3];
        for(int i=0;i<3;i++)
            temp[(i+x)%3]=segtree[node].mod[i];
        for(int i=0;i<3;i++)
            segtree[node].mod[i]=temp[i];
        lazy[2*node]+= x;
        lazy[2*node+1]+=x;
    }
     if(qr<l || ql>r)
        return block();
    if(ql<= l && qr>=r)
        return segtree[node];
    int m = (l+r)/2;
    block b1 = query(2*node,l,m,ql,qr);
    block b2 = query(2*node+1,m+1,r,ql,qr);
    block ret;
    for(int i=0;i<3;i++)
        ret.mod[i]=b1.mod[i]+b2.mod[i];
    return ret;
}
void update(int node,int l,int r,int ql,int qr)
{
    if(lazy[node]!=0)
    {
        int x= lazy[node];
        lazy[node]=0;
        int temp[3];
       for(int i=0;i<3;i++)
            temp[(i+x)%3]=segtree[node].mod[i];
        for(int i=0;i<3;i++)
            segtree[node].mod[i]=temp[i];
        lazy[2*node]+= x;
        lazy[2*node+1]+=x;
    }
    if(qr<l || ql>r)
        return;
    if(ql<=l && qr>=r)
    {
        int temp[3];
       for(int i=0;i<3;i++)
            temp[(i+1)%3]=segtree[node].mod[i];
        for(int i=0;i<3;i++)
            segtree[node].mod[i]=temp[i];
        lazy[2*node]+= 1;
        lazy[2*node+1]+=1;
        return ;
    }
    int m = (l+r)/2;
    update(2*node,l,m,ql,qr);
    update(2*node+1,m+1,r,ql,qr);
    block b1 = segtree[2*node];
    block b2 = segtree[2*node+1];
    for(int i=0;i<3;i++)
        segtree[node].mod[i]=b1.mod[i]+b2.mod[i];
   }
int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        l++;
        r++;
        if(t==0)
        {
            update(1,1,n,l,r);
        }
        else
        {
            block ans  = query(1,1,n,l,r);
            cout<<ans.mod[0]<<"\n";
        }
    }
    return 0;
}
