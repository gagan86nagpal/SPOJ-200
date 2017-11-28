#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
int main()
{
    int t,T;
    cin>>t;
    T=t;
    while(t--)
    {
        int sum,n,i;
        cin>>sum>>n;
        a.clear();
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),greater<int>());
        int req=0;
        for(i=0;i<n;i++)
        {
            req+=a[i];
            if(req>=sum)
            {
                break;
            }
        }
        cout<<"Scenario #"<<T-t<<":\n";
        if(req>=sum)
            cout<<i+1<<"\n";
        else
            cout<<"impossible\n";
    }
    return 0;
}
