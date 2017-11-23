#include <iostream>

using namespace std;

int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            return 0;
        int ans=0,i;
        for(i=1;i<=n;i++)
            ans+=i*i;
        cout<<ans<<"\n";
    }
    return 0;
}
