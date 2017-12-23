#include <iostream>

using namespace std;
int conv(char c)
{
    if(c>='A' && c<='Z')
        return c-'A'+'a';
    return c;
}
int main()
{
    while(true)
    {
        string s;
        getline(cin,s);
        if(s=="*")
            break;
        int flag = conv(s[0]);
        string ans="Y";
        for(int i=1;i<s.size()-1;i++)
            if(s[i]==' ')
            {
                if(conv(s[i+1])!=flag)
                {
                    ans = "N";
                    break;
                }
            }
        cout<<ans<<"\n";
    }
    return 0;
}
