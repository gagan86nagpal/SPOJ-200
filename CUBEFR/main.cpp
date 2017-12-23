#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
int a[30]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
int b[30];
int c[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    int n=26;
    int i,j;
    for(i=0;i<n;i++)
        b[i]=a[i]*a[i]*a[i];
    int pos=1;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=125000;j++)
        {
            if(b[i]*j >1000000)
                break;
            c[b[i]*j]=-1;
        }
    }
    for(i=1;i<=1000000;i++)
        if(c[i]!=-1)
            c[i]=pos++;
  int t,tc=0;;
  cin>>t;
  while(t--)
  {
      tc++;
      int n;
      cin>>n;
      cout<<"Case "<<tc<<": ";
      if(c[n]==-1)
        cout<<"Not Cube Free\n";
      else
        cout<<c[n]<<"\n";
  }
    return 0;
}
