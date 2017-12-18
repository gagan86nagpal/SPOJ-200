#include <iostream>
#include <map>
#include <utility>
using namespace std;

map < pair<int,pair<int,int> > , int> m;
int solve(int h,int a,int ch)
{
    if(h<=0 || a<=0)
        return -1;
    if(m.find({h,{a,ch}})!=m.end())
        return m[{h,{a,ch}}];

    if(ch==0) // air
    {
        return m[{h,{a,ch}}]=1+max(solve(h-5,a-10,1),solve(h-20,a+5,2));
    }
    else if(ch==1) // water
    {
        return m[{h,{a,ch}}]=1+max(solve(h+3,a+2,0),solve(h-20,a+5,2));
    }
    else
    {
        return m[{h,{a,ch}}]=1+solve(h+3,a+2,0);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        int h,a;
        cin>>h>>a;
        int ans = solve(h+3,a+2,0)+1;
        cout<<ans<<"\n";
    }
    return 0;
}
