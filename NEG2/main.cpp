#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector < pair <long long , long long> > pos;
vector < pair <long long , long long> > neg;

string gen(vector<pair <long long,long long> > v,long long n)
{
    if(n<0)
        n*=-1;
    string ans="";
    long long pow=1;
    for(pair <long long,long long > p :v)
    {
        if(p.first > n)
            break;
        long long  m = n%(long long)abs(2*pow);
        if(p.first <= m && p.second >=m)
            ans.push_back('1');
        else
            ans.push_back('0');
        pow*=-2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    long long l=1;
    long long pow=1;
    long long i,n=35;
    for(i=1;i<=n;i++)
    {
        pos.push_back({l,l+pow-1});
        if(i%2==1)
            l+=pow;
        pow*=2;
    }
    l=1;
    pow=1;
    for(i=1;i<=n;i++)
    {
        neg.push_back({l,l+pow-1});
        if(i%2==0)
            l+=pow;
        pow*=2;
    }
    long long t;
    cin>>t;
    string ans="";
    if(t==0)
        ans="0";
    else
        ans=gen((t>0)?pos:neg,t);
    cout<<ans<<"\n";
    return 0;
}
