#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< int> v;
int main()
{
    ios_base::sync_with_stdio(false);
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
            v.push_back(x);
        }
        for(i=v.size()-1;i>=1;i--)
        {
            if(v[i-1] < v[i])
                break;
        }
        if(i==0)
        {
            cout<<-1<<"\n";
            continue;
        }
        int pos=i+1;
        while(pos<n&&v[pos]>v[i-1])
            pos++;
        swap(v[pos-1],v[i-1]);
        sort(v.begin()+i,v.end());
        for(int x: v)
            cout<<x;
        cout<<"\n";
    }
    return 0;
}
