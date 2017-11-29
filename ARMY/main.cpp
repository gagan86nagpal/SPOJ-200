#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        int x,m1=-1,m2=-1;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            m1 =max(m1,x);
        }
        for(int i=0;i<m;i++)
        {
            cin>>x;
            m2 = max(m2,x);
        }
        if(m1>=m2)
        {
            cout<<"Godzilla\n";
        }
        else
            cout<<"MechaGodzilla\n";
    }
    return 0;
}
