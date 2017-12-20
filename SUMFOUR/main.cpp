#include <iostream>
#include <algorithm>
using namespace std;
int a[2501][5];
int b[6250001];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<4;j++)
            cin>>a[i][j];
    int len=0;
    int val;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            val = a[i][0]+a[j][1];
            b[len++]=val;
        }
    sort(b,b+len);
     int ans=0;
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            val = a[i][2]+a[j][3];
            val*=-1;
            pair <int*,int*> p=equal_range(b,b+len,val);
            ans+=p.second-p.first;
        }
        cout<<ans<<"\n";


    return 0;
}
