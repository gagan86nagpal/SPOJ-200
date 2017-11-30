#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        int g,b;
        cin>>g>>b;
        if(g==-1 &&b==-1)
            break;
        if(g>b)
            swap(g,b);
        cout<<(b+g)/(g+1)<<"\n";
    }
    return 0;
}
