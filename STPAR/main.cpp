#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector <int> v;
stack <int> s;
int main()
{

    while(true)
    {
        while(!s.empty())
            s.pop();
        v.clear();
        int n;
        cin>>n;
        if(n==0)
            break;
        int i;
        int exp=1;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x==exp)
            {
                exp++;
                v.push_back(x);
            }
            else
            {
                s.push(x);
            }
            while(!s.empty() && s.top()==exp)
            {
                v.push_back(s.top());
                s.pop();
                exp++;
            }
        }
        if(v.size()==n)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;

}
