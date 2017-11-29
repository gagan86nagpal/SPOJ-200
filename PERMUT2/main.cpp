#include <iostream>

using namespace std;
int a[100001];
int in[100001];
int main()
{
    while(true)
    {
        int n;
        int i;
        cin>>n;
        if(n==0)
            break;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            in[a[i]]=i;
        bool flag = true;
        for(i=1;i<=n;i++)
            if(a[i]!=in[i])
            {
                flag = false;
                break;
            }
        if(!flag)
            cout<<"not ambiguous\n";
        else
            cout<<"ambiguous\n";
    }
    return 0;
}
