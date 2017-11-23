#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        string st;
        cin>>st;
        string ans="";
        int i;
        for(i=1;i<st.size();i++)
        {
            if(i%n==0 && i+n<=st.size()  && (i/n)%2==1 )
                reverse(st.begin()+i,st.begin()+i+n);
        }
        for(i=0;i<n;i++)
        {
            int j;
            for(j=0;j<st.size()/n;j++)
                ans.push_back(st[j*n+i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
