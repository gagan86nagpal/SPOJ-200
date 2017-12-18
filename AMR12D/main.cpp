#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string r = s;
        reverse(s.begin(),s.end());
        string ans = "YES\n";
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(c!=r[i])
            {
                ans = "NO\n";
                break;
            }
        }
        cout<<ans;
    }
    return 0;
}
