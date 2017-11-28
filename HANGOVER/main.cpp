#include <iostream>

using namespace std;
double arr[300];

int ubound(int l,int r,double h)
{
    while(l<r)
    {
        int m  = (l+r)/2;
        if(arr[m]<h)
            l=m+1;
        else
            r=m;
    }
    return r;
}
int main()
{
    int i;
    double h=0.0;
    for(i=1;i<=280;i++)
    {
        h+=1/(double)(i+1);
        arr[i]=h;
    }

    while(true)
    {
        cin>>h;
        if(h==0.0)
            break;
        i=ubound(1,280,h);
        cout<<i<<" card(s)\n";
    }
    return 0;
}
