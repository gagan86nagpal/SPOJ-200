#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(m>=n)
            if(n%2==0)
                cout<<"L\n";
            else
                cout<<"R\n";
        else
            if(m%2==0)
                cout<<"U\n";
            else
                cout<<"D\n";
    }
    return 0;
}
