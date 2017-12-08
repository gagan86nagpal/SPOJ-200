#include <iostream>

using namespace std;
long long strtoi(string s)
{
    long long ret=0;
    for(char c : s)
    {
        ret= ret*10 + c-'0';
    }
    //cout<<s<<" : "<<ret<<"\n";
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        string s;
        cin>>s;
        ans = strtoi(s);
        while(true)
        {
            cin>>s;
            if(s=="=")
                break;
            if(s=="+")
            {
                cin>>s;
                ans = ans+strtoi(s);
            }
            else if(s=="-")
            {
                cin>>s;
                ans-=strtoi(s);
            }
            else if(s=="*")
            {
                cin>>s;
                ans*=strtoi(s);
            }
            else
            {
                cin>>s;
                ans/=strtoi(s);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
