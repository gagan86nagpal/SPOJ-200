#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        string n;
        cin>>n;
        string dec="";
        int i;
        for(i=0;i<n.size();i++)
        {
            if(n[i]=='.')
            {
                dec = n.substr(i+1);
                break;
            }
        }
        if(dec=="")
            cout<<1<<"\n";
        else
        {

            int x=0;
            for(char c:dec)
                x=x*10  + c-'0';

            for(i=0;i<(4-dec.size());i++)
                x*=10;
            int ans;
            for(i=1;i<=10000;i++)
            {
                int y = x*i;
                if(y%10000 ==0)
                {
                    ans =i;
                    break;
                }
            }
            cout<<ans<<"\n";
        }

    }
    return 0;
}
