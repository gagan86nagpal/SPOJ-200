#include <iostream>
#include <cmath>
using namespace std;
bool is_pefect_square(long long n)
{
    long long sq = sqrt(n);
    return sq*sq==n;
}
int main()
{
    while(true)
    {
        long long n;
        cin>>n;
        if(n==-1)
            break;
        cout<<(is_pefect_square(12*n-3)?"Y\n":"N\n");
    }
    return 0;
}
