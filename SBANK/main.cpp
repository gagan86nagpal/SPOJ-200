#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
map <string,int> m;
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        int n;
        m.clear();
        scanf("%d\n",&n);
        while(n--)
        {
            string s;
            getline(cin,s);
            m[s]=m[s]+1;
        }
        for(pair <string,int> p: m)
            cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}
