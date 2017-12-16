#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        s.clear();
        int n,m,d;
        cin>>n>>m>>d;
        while(n--)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        bool flag  =true;
        while(m--)
        {
            int x =*s.rbegin();
            s.erase(--s.end());
            if(x<=d)
            {
                flag= false;
                break;
            }
            else
            {
                s.insert(x-d);
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
