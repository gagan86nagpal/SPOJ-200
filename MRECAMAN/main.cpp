#include <iostream>
using namespace std;
int a[500004];
int m[8000000];
void gen(int n)
{
    int i;
    m[0]=1;
    for(i=1;i<=n;i++)
    {
        a[i]=a[i-1]-i;
        if(!(m[a[i]]==0 && a[i]>0))
            a[i]=a[i-1]+i;
        m[a[i]]=1;
    }
}
int main()
{
    gen(500002);
    while(true)
    {
        int n;
        cin>>n;
        if(n==-1)
            break;
        cout<<a[n]<<"\n";
    }
    return 0;
}
