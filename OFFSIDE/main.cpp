#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> av,bv;

int main()
{
    while(true)
    {
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0)
            break;
        int i;
        av.clear();
        bv.clear();
        for(i=0;i<a;i++)
        {
            int x;
            cin>>x;
            av.push_back(x);
        }
        for(i=0;i<b;i++)
        {
            int x;
            cin>>x;
            bv.push_back(x);
        }
        sort(av.begin(),av.end());
        sort(bv.begin(),bv.end());
        if(bv[0] <= av[0] && bv[1] <=av[0])
            cout<<"N\n";
        else
            cout<<"Y\n";

    }
    return 0;
}
