#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=0,b=0,c=0;
    while(n--)
    {
        string s;
        cin>>s;
        if(s[s.size()-1]=='2')
            b++;
       else if(s[0]=='3')
            c++;
        else
            a++;
    }
    int d= max(a-c,0);
    if(b%2==1&&d>0)
        d-=2;
    int ans =1+c+ (b+1)/2 + (d+3)/4;
    cout<<ans<<"\n";
    return 0;
}
