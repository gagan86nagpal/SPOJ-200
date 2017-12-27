#include <iostream>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        tc++;
        int a,b,c;
        cin>>a>>b>>c;
        int g= gcd(a,b);
        cout<<"Case "<<tc<<": ";
        if(c%g==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
