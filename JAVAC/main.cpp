#include <iostream>

using namespace std;

bool isLower(char c)
{
    return (c>='a' && c<='z');
}
bool isUpper(char c)
{
    return (c>='A' && c<='Z');
}
bool isDigit(char c)
{
    return (c>='0' && c<='9');
}
bool lowerOrDigit(char c)
{
    return isLower(c)||isDigit(c);
}
bool isJava(string s)
{
    if(s[0]=='_' || s[s.size()-1]=='_' || (!islower(s[0])))
        return false;
    bool flag =true;
    for(char c:s)
    {
        if(isLower(c) || isUpper(c) ||isdigit(c) )
            continue;
        flag=false;
        break;
    }
    return flag;
}
bool isC(string s)
{
    if(!(lowerOrDigit(s[0]) && lowerOrDigit(s[s.size()-1])))
        return false;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(c=='_' && s[i+1]=='_')
            return false;
        if(c=='_'||isLower(c)||isdigit(c))
            continue;
        return false;
    }
    return true;
}
string jtc(string s)
{
    string ret="";
    for(char c:s)
    {
        if(lowerOrDigit(c))
            ret.push_back(c);
        else
        {
            ret.push_back('_');
            if(isUpper(c))
                c=c-'A'+'a';
            ret.push_back(c);
        }
    }
    return ret;
}
string ctj(string s)
{
    string ret="";
    for(int i=0;i<s.size();i++)
    {
        char c = s[i];
        if(c=='_')
        {
            i++;
            c=s[i];
            if(isLower(c))
            c=c-'a'+'A';
        }
        ret.push_back(c);
    }
    return ret;
}
int main()
{
    string s;
    while(cin>>s)
    {
        bool j,c;
        c=isC(s);
        j =isJava(s);
        if(c)
            cout<<ctj(s)<<"\n";
        else if(j)
            cout<<jtc(s)<<"\n";
        else
            cout<<"Error!\n";
    }
    return 0;
}
