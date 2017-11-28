#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    if(__builtin_popcountll(n)==1)
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
    return 0;
}
