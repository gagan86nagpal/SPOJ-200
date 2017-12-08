#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <string,int> m;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        m.clear();
        m["TTT"]=0;
        m["TTH"]=0;
        m["THT"]=0;
        m["THH"]=0;
        m["HTT"]=0;
        m["HTH"]=0;
        m["HHT"]=0;
        m["HHH"]=0;
        for(int i=0;i<s.size()-2;i++)
        {
            string st = s.substr(i,3);
            m[st] = m[st]+1;
        }
        cout<<n<<" ";
        vector <int> ans;
        for( pair<string,int> p : m)
            ans.push_back(p.second);
        reverse(ans.begin(),ans.end());
        for(int x: ans)
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}
