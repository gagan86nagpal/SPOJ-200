#include <iostream>
using namespace std;

int m1[27];
int m2[27];
int main()
{
    string ans="";
    string s,t;
    while(cin>>s)
    {
        ans="";
        cin>>t;
        int i;
        for(i=0;i<26;i++)
            m1[i]=m2[i]=0;
        for(char c: s)
            m1[c-'a']++;
        for(char c: t)
            m2[c-'a']++;
        for(i=0;i<26;i++)
        {
            int val = min(m1[i],m2[i]);
            while(val--)
            {
                ans.push_back('a'+i);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
