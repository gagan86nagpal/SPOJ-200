#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair <int,int> >v;
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
            int s,e;
            cin>>s>>e;
            v.push_back({s,1});
            v.push_back({e,-1});
        }
        sort(v.begin(),v.end());
    int cnt=0,ans=0;
    for(pair <int,int> p :v)
    {
        cnt+=p.second;
        ans = max(ans,cnt);
    }
    cout<<ans<<"\n";
    }
    return 0;
}
