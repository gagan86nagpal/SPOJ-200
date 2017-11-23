#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        int ans;
        if(x==0&&y==0)
            ans=0;
        else if(x==1&&y==1)
            ans=1;
        else if(x==y ||x-2==y)
        {
            int d=x-y;
            ans=x*2 -x%2 -d;
        }
        else
        {
            ans=-1;
        }
        if(ans==-1)
            cout<<"No Number\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}
