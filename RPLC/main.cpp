#include <iostream>

using namespace std;

int main()
{
    long long t;
    long long tc=0;
    cin>>t;
    while(t--)
    {
        tc++;
        long long n,x;
        cin>>n;
        long long i;
        long long cum=0;
        long long ans=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            cum+=x;
            ans = min(ans,cum);
        }
        ans*=-1;
        cout<<"Scenario #"<<tc<<": ";
        cout<<ans+1<<"\n";
    }
    return 0;
}
