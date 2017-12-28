#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
string s;
int n;
bool cmp(int a,int b)
{
    string s1=s.substr(a,n),s2=s.substr(b,n);
    if(s1==s2)
        return a<b;
    else
        return s1<s2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        s.clear();
        cin>>s;
        n=s.size();
        int mini = 250;
        for(char c:s)
            mini = min((int)c,mini);
        for(int i=0;i<s.size();i++)
            if(s[i]==mini)
                v.push_back(1+i);
        s=s+s;
        sort(v.begin(),v.end(),cmp);
        cout<<v[0]<<"\n";
    }
    return 0;
}
