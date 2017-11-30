#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< int> v;
bool isPossible(int m,int c)
{
    int i;
    c--;
    int prev=v[0];
    for(i=0;i<c;i++)
    {
        int in = lower_bound(v.begin(),v.end(),prev+m) - v.begin();
        if(in>=v.size())
            return false;
        prev = v[in];
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        v.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int l =0;
        int r=v[v.size()-1];
        while(l<r)
        {
            int m;
            m = (l +r)/2;
            if(isPossible(m,c))
                l=m+1;
            else
                r=m;
        }
        cout<<l-1<<"\n";
    }
    return 0;
}
