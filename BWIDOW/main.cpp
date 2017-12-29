#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair <int,pair <int,int> > > v;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i;
    cin>>t;
    while(t--)
    {
        v.clear();
        int n;
        cin>>n;
        for(i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            v.push_back({a,{b,i+1}});
        }
        sort(v.begin(),v.end());
        int x = v[v.size()-1].first;
        int y=-1;
        int pos=v[v.size()-1].second.second;
        for(i=0;i<v.size()-1;i++)
            if(y<v[i].second.first)
                y=v[i].second.first;
        if(x<=y)
            pos=-1;
        cout<<pos<<"\n";

    }
    return 0;
}
