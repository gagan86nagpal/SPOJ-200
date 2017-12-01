#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    int ans =0;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ans^=x;
    }
    cout<<ans<<"\n";
    return 0;
}
