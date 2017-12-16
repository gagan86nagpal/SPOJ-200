#include <iostream>

using namespace std;
#define inf 10000000
struct block
{
    int sum;
    int pre;
    int post;
    int ans;
};

block tree[200002];
int a[50002];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]={a[l],a[l],a[l],a[l]};
        return ;
    }
    int m =(l+r)/2;
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    block b1 = tree[2*node];
    block b2 = tree[2*node+1];
    tree[node]={b1.sum+b2.sum,max(b1.pre,b1.sum+b2.pre),max(b2.post,b2.sum+b1.post),max(b1.post+b2.pre,max(b1.ans,b2.ans))};
}

block query(int node,int l,int r,int ql,int qr)
{
    if(qr<l || ql>r)
        return block{-inf,-inf,-inf,-inf};
    if(ql<=l && qr>=r)
        return tree[node];
    int m = (l+r)/2;
    block b1 = query(2*node,l,m,ql,qr);
    block b2 = query(2*node+1,m+1,r,ql,qr);
    block b3={b1.sum+b2.sum,max(b1.pre,b1.sum+b2.pre),max(b2.post,b2.sum+b1.post),max(b1.post+b2.pre,max(b1.ans,b2.ans))};
    return b3;
}

void update(int node,int l,int r,int i,int x)
{
    if(l==r)
    {
        tree[node]={x,x,x,x};
        return ;
    }
    int m =(l+r)/2;
    if(i<=m)
        update(2*node,l,m,i,x);
    else
        update(2*node+1,m+1,r,i,x);
    block b1 = tree[2*node];
    block b2 = tree[2*node+1];
    tree[node]={b1.sum+b2.sum,max(b1.pre,b1.sum+b2.pre),max(b2.post,b2.sum+b1.post),max(b1.post+b2.pre,max(b1.ans,b2.ans))};

}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
  //  cin>>t;
    t=1;
    while(t--)
    {
        int n;
        int i;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
        int m;
        cin>>m;
        for(i=0;i<m;i++)
        {
            int q;
            cin>>q;

            int l,r;
            cin>>l>>r;
            if(q==1)
            {
                block b = query(1,1,n,l,r);
                cout<<b.ans<<"\n";
            }
            else
            {
                update(1,1,n,l,r);
            }
        }
    }
    return 0;
}
