#include <iostream>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int pour(int a,int b,int c)
{
    int sa,sb;
    sa=0;
    sb=0;
    int cnt=0,d;
    do
    {
        if(sa==c || sb==c)
            break;
        cnt++;
        if(sb<b)
            if(sa==0)
              sa=a;
            else
                d=min(sa,b-sb),sa-=d,sb+=d;
        else
            sb=0;
    }
    while(!(sa==0 && sb==0));
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,ans;
        cin>>a>>b>>c;
        if(c > max(a,b))
            ans=-1;
        else if(c%gcd(a,b)!=0)
            ans=-1;
        else
            ans = min(pour(a,b,c), pour(b,a,c));
        cout<<ans<<"\n";
    }
    return 0;
}
