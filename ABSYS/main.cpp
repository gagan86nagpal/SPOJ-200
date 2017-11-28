#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if(a.find('m')!=string::npos)
        {
            int na = atoi(e.c_str()) - atoi(c.c_str());
            cout<<na<<" "<<b<<" " <<c<< " "<<d<<" "<<e<<"\n";
        }
        else if(c.find('m')!=string::npos)
        {
            int nc =atoi(e.c_str()) - atoi(a.c_str());
            cout<<a<<" "<<b<<" "<<nc<<" " <<d<< " "<<e<<"\n";
        }
        else
        {
            int ne = atoi(a.c_str()) + atoi(c.c_str());
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<ne<<"\n";
        }
    }
    return 0;
}
