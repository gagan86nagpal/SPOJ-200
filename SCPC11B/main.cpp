#include <iostream>
#include <algorithm>
using namespace std;
int a[1500];
int main()
{
    ios_base::sync_with_stdio(false);
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int i;
        bool flag =true;
        a[0]=0;
        for(i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=1422;
        n+=2;
        sort(a,a+n);
        for(i=1;i<n;i++)
            if(a[i]-a[i-1]>200)
                {
                    flag = false;
                    break;
                }
        sort(a,a+n,greater<int>());
        for(i=1;i<n;i++)
        {
            if(a[i]-a[i-1]>200)
            {
                flag=false;
                break;
            }
        }
        if(flag&& a[1]>=1322)
            cout<<"POSSIBLE\n";
        else
            cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
