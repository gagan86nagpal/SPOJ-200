#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a,b;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        a.clear();
        b.clear();
        int i,x;
        for(i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        for(i=0;i<n;i++)
        {
            cin>>x;
            b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(i=0;i<n;i++)
            sum+=a[i]*b[i];
        cout<<sum<<"\n";
    }
    return 0;
}
