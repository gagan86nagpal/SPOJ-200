#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector <int> v;
int main()
{
    string s;
    int t;
    cin>>t;
    getline(cin,s);
    while(t--)
    {
        v.clear();
        getline(cin,s);
        istringstream iss(s,istringstream::in);
        string word;
        while(iss>>word)
            v.push_back(word.size());;
        int ans=0;
        int pos=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1])
                pos++;
            else
                ans = max(ans,pos),pos=1;
        }
        ans = max(ans,pos);
        cout<<ans<<"\n";
    }
    return 0;
}
