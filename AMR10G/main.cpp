#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> v;
set<int> s;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        s.clear();
        int n,k;
        cin>>n>>k;
        int i;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(i=0;i<k;i++)
            s.insert(v[i]);
        int ans = *s.rbegin() - *s.begin();
        while(i<n)
        {
            s.erase(v[i-k]);
            s.insert(v[i]);
            int val =*s.rbegin() - *s.begin();
            if(ans > val)
                ans = val;
            i++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
