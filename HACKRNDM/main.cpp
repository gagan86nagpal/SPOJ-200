#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    long long cnt=0;
    for(int x: s)
    {
        int y = x+k;
        if(s.find(y)!=s.end())
            cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}
