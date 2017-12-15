#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
vector < int> preprocess;
string needle,haystack;
int main()
{
    int n;
    while(scanf("%d\n",&n)!=EOF)
    {
        getline(cin,needle);
        getline(cin,haystack);
        int found=-1;
        while(true)
        {
            found = haystack.find(needle,found+1);
            if(found==string::npos)
            {
                break;
            }
            else
            {
                cout<<found<<"\n";
            }
        }
        cout<<"\n";
    }
    return 0;
}
