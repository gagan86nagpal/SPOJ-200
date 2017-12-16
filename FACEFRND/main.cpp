#include <iostream>

using namespace std;
int m[100001];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int id,k;
        cin>>id>>k;
        m[id]=1;
        while(k--)
        {
            cin>>id;
            m[id]=1;
        }
    }
    int cnt=0;
    for(i=0;i<=9999;i++)
        cnt+=m[i];
    cnt-=n;
    cout<<cnt<<"\n";
    return 0;
}
