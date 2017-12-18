#include <iostream>
#include <map>
using namespace std;


map <int,int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        int n;
        cin>>n;
        int i;
        int ma=0;
        int val=-100000;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            m[x]=m[x]+1;
            if(m[x]>ma)
            {
                ma = m[x];
                val = x;
            }
        }
        if(ma>n/2)
            cout<<"YES "<<val<<"\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
