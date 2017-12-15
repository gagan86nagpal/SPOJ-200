#include <iostream>
#include <stack>
using namespace std;
stack<char> st;
int main()
{
    string s;
    int tc=0;
    while(true)
    {
        tc++;
        while(!st.empty())
            st.pop();
        cin>>s;
        if(s[0]=='-')
            break;
        int ans=0;
        for(char c: s)
        {
            if(c=='{')
                st.push(c);
            else
            {
                if(!st.empty())
                    st.pop();
                else
                    st.push('{'),ans++;
            }
        }
        ans+=st.size()/2;
        cout<<tc<<". "<<ans<<"\n";
    }
    return 0;
}
