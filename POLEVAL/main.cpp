#include <iostream>

using namespace std;
long long c[1100];
long long k[110];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc=0;
    while(true)
    {
        tc++;
        long long nc,nk;
        cin>>nc;
        if(nc==-1)
            break;
        cout<<"Case "<<tc<<":\n";
        int i;
        for(i=0;i<=nc;i++)
            cin>>c[i];
        cin>>nk;
        for(i=0;i<nk;i++)
            cin>>k[i];

        long long ans;
        for(i=0;i<nk;i++)
        {
            long long x = k[i];
            int j =0;
            ans=0;
            while(j<=nc)
            {
                ans*=x;
                ans+=c[j];
                j++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
