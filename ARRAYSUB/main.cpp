#include <iostream>
#include <set>
using namespace std;
multiset <int> m;
int a[100002];
int main()
{
    int n,k;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>k;
    for(i=0;i<k;i++)
        m.insert(a[i]);
    while(i<n)
    {
        cout<<*m.rbegin()<<" ";
        m.erase(m.find(a[i-k]));
        m.insert(a[i]);
        i++;
    }
    cout<<*m.rbegin()<<"\n";
    return 0;
}
