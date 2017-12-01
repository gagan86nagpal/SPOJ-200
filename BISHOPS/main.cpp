#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector< int> v;

vector <int> sub(vector <int> a,vector <int>b) // a-b and a >b
{
    vector <int> ret;
    int i,j;
    i=a.size()-1;
    j=b.size()-1;
    int diff;
    while(i>=0&&j>=0)
    {
        if(a[i]<b[j])
        {
            a[i]+=10;
            a[i-1]--;
        }
        diff=a[i]-b[j];
        i--;
        j--;
        ret.push_back(diff);
    }
    while(i>=0)
    {
        if(a[i]<0)
            a[i]+=10,a[i-1]--;
        ret.push_back(a[i]);
        i--;
    }

    for(i=ret.size()-1;i>=0;i--)
        if(ret[i]==0)
            ret.pop_back();
        else
            break;
    reverse(ret.begin(),ret.end());
    return ret;
}
vector<int> add(vector <int> a,vector<int>b) //  a+b, a>b
{
    int i,j;
    i=a.size()-1;
    j = b.size()-1;
    vector <int> ret;
    int sum=0,carry=0;
    while(i>=0&&j>=0)
    {
        sum = (a[i]+b[j]+carry)%10;
        carry =(a[i] + b[j]+carry)/10;
        ret.push_back(sum);
        i--;
        j--;
    }
    while(i>=0)
    {
        sum = (a[i]+carry)%10;
        carry =(a[i] +carry)/10;
        ret.push_back(sum);
        i--;
    }
    if(carry>0)
        ret.push_back(carry);
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    string st;
    while(cin>>st)
    {
        if(st=="1")
        {
            cout<<st<<"\n";
            continue;
        }

        v.clear();
        for(int i=0;i<st.size();i++)
            v.push_back(st[i]-'0');
        vector <int> two = {2};
        vector <int> t1 = sub(v,two);
        vector<int> ans = add(v,t1);
        for(int x: ans)
            cout<<x;
        cout<<"\n";
    }
    return 0;
}
