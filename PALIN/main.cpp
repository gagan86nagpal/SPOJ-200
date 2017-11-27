#include <iostream>
#include <vector>
using namespace std;

bool comp(vector <int> &a,vector<int> &b) // true if a>b
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>b[i])
            return true;
        else if(a[i] <b[i])
            return false;
    }
    return false;
}
vector<int> solve(vector<int> a)
{
    vector <int> ret;
    int d= a.size();
    int i;
    for(i=0;i<(d+1)/2;i++)
        ret.push_back(a[i]);
    for(i=(d+1)/2;i<d;i++ )
        ret.push_back(a[d-1-i]);
    if(comp(ret,a))
        return ret;
    for(i= (d-1)/2;i>=0;i-- )
    {
        if(ret[i]!=9)
            break;
    }
    if(i==-1) // all 9's
    {
        ret.clear();
        for(i=0;i<=d;i++)
            if(i%d==0)
                ret.push_back(1);
            else
                ret.push_back(0);
    }
    else
    {

        ret[i]++;
        ret[d-1-i]=ret[i];
        for(int j=i+1;j<= d-2-i;j++)
            ret[j]=0;
    }
    return ret;


}
int main()
{
    vector <int> in;
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        in.clear();
        int i;
        bool flag=false;
        for(i=0;i<s.size();i++)
        {
            if(s[i]!='0')
                flag=true;
            if(flag)
                in.push_back(s[i]-'0');
        }

        vector<int> ret = solve(in);
        for(int x:ret)
            cout<<x;
        cout<<"\n";
    }
    return 0;
}
