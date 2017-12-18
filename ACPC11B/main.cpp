#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
vector<pair<int,int> > v;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back({x,1});
        }
        cin>>n;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back({x,2});
        }
        sort(v.begin(),v.end());
        int ans=10000002;
        for(i=0;i<(int)v.size()-1;i++)
        {
            if(v[i].second!=v[i+1].second)
                ans = min(ans,abs(v[i].first-v[i+1].first) );
        }
        cout<<ans<<"\n";
    }
    return 0;
}
