#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int change(int n)
{
    vector<int> v;
    while(n>0)
    {
        v.push_back(n%2);
        n/=2;
    }
    reverse(v.begin(),v.end());
    int pow=1;
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans+=pow*v[i];
        pow*=2;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        if(x%2==0)
            x = change(x);
        cout<<x<<"\n";
    }
    return 0;
}
