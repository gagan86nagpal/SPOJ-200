#include <iostream>

using namespace std;
int a[200002];
int aux[200002];
long long cnt;
void merge_(int a[200002],int l,int m,int r)
{
    int s1=l,e1=m,s2=m+1,e2=r;
    int i=s1,j=s2,k=0;
    while(i<=e1 && j<=e2)
    {
        if(a[i] > a[j])
        {
            cnt+=e1-i+1;
            aux[k++]=a[j++];
        }
        else
            aux[k++]=a[i++];
    }
    while(i<=e1)
        aux[k++]=a[i++];
    while(j<=e2)
        aux[k++]=a[j++];
    for(i=0;i<k;i++)
        a[l+i]=aux[i];
}
void merge_sort(int a[200002],int l,int r)
{
    if(l>=r)
        return;
    int m = (l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge_(a,l,m,r);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        int i,n;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];

        merge_sort(a,0,n-1);
        cout<<cnt<<"\n";
    }
    return 0;
}
