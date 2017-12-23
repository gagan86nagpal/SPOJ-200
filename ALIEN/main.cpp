#include <iostream>

using namespace std;
int a[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ma,i;
        cin>>n>>ma;
        for(i=0;i<n;i++)
            cin>>a[i];
        i=0;
        int j=0;
        int sum=0;
        int a1=-1,a2=-1;
        while(i<n)
        {
            if(sum+a[i]<=ma)
                sum+=a[i++];
            else
            {
                if(a2==-1) // not selected yet
                    a2 =sum,a1 = i-j;
                else if(i-j >a1)
                    a1=i-j,a2=sum;
                else if(i-j==a1 && sum<a2)
                    a1=i-j,a2=sum;
                sum-=a[j];
                j++;
            }
        }
        if(a2==-1) // not selected yet
            a2 =sum,a1 = i-j;
        else if(i-j >a1)
            a1=i-j,a2=sum;
        else if(i-j==a1 && sum<a2)
            a1=i-j,a2=sum;
        cout<<a2<<" "<<a1<<"\n";
    }
    return 0;
}
