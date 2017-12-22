#include <iostream>

using namespace std;
int a[10002];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,i;
        cin>>n>>u;
        for(i=0;i<=n;i++)
            a[i]=0;
        while(u--)
        {
            int l,r,val;
            cin>>l>>r>>val;
            a[l]+=val;
            a[r+1]-=val;
        }
        for(i=1;i<=n;i++)
            a[i]+=a[i-1];
        int q;
        cin>>q;
        while(q--)
        {
            int x;
            cin>>x;
            cout<<a[x]<<"\n";
        }
    }
    return 0;
}
