#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int i;
        cin>>n;
        double ans =0;
        for(i=1;i<=n;i++)
            ans+=(double)n/i;
        printf("%.2f\n",ans);
    }
    return 0;
}
