#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


vector < pair <int,int> > v;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        v.clear();
        int i;
        for(i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            v.push_back({b,a});
        }
        sort(v.begin(),v.end());
        int ti=-1;
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(ti<=v[i].second)
                ti = v[i].first,cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
