#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    int i,j;
    for(i=1;i*i<=n;i++)
    {
        for(j=i*i;j<=n;j+=i)
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
