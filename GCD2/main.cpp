#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

vector<int> b1;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int mod(int a ,vector<int> b)
{
    if(a==0)
        return 0;
    int i,n;
    i=0;
    n=0;
    while(i<b.size())
    {
        while(i<b.size()&&n<a)
            n=n*10 + b[i++];
        n=n%a;
    }
    return n;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        b1.clear();
        int a;
        string b;
        cin>>a>>b;
        if(a==0)
            cout<<b<<"\n";
        else if(b.size()<9)
            cout<<gcd(a,atoi(b.c_str()))<<"\n";
        else
        {
            for(char c: b)
                b1.push_back(c-'0');
            int c =mod(a,b1);
            cout<<gcd(a,c)<<"\n";
        }
    }
    return 0;
}
