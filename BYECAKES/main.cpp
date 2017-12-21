#include <iostream>

using namespace std;
int a[5];
int b[5];
int main()
{
    int i;
    while(true)
    {
        for(i=0;i<4;i++)
            cin>>a[i];
        for(i=0;i<4;i++)
            cin>>b[i];
        if(a[0]==-1)
            break;
        int d=0;
        for(i=0;i<4;i++)
        {
            d = max(d,(a[i]+b[i]-1)/b[i] );
        }
        for(i=0;i<4;i++)
        {
            cout<<d*b[i]-a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
