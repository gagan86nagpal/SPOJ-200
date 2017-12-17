#include <iostream>
#include <map>
using namespace std;
int a[10003];
int b[10003];
int main()
{
    while(true)
    {
        int n,m;
        cin>>n;
        if(n==0)
            break;
        int i,j;
        for(i=0;i<n;i++)
            cin>>a[i];
        a[i]=1000000;
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>b[i];
        }
        b[i]=1000000;
        int ans=0;
        int suma=0,sumb=0;
        i=0;
        j=0;
        while(i<=n && j<=m)
        {
            if(a[i]>b[j])
                sumb+=b[j++];
            else if(a[i]<b[j])
                suma+=a[i++];
            else
            {
                ans+=a[i];
                i++;
                j++;
                ans+=max(suma,sumb);
                suma=0;
                sumb=0;
            }
        }

        cout<<ans-1000000<<"\n";
    }
    return 0;
}
