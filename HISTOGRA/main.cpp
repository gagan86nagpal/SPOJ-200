#include <iostream>
#include <stack>
using namespace std;

stack <int> st;
long long a[100002];
int l[100002];
int r[100002];
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        long long ans;
        for(i=0;i<n;i++)
        {
            if(st.empty() || a[st.top()]<=a[i] )
                st.push(i);
            else
            while(!st.empty() && a[st.top()]>a[i])
            {
                int j = st.top();
                st.pop();
                r[j]=i;
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int j = st.top();
            st.pop();
            r[j]=n;
        }
        for(i=n-1;i>=0;i--)
        {
            if(st.empty()||a[st.top()]<=a[i])
                st.push(i);
            else
            {
                while(!st.empty() && a[st.top()]>a[i])
                {
                    int j = st.top();
                    st.pop();
                    l[j]=i;
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            int j = st.top();
            st.pop();
            l[j]=-1;
        }
        for(i=0;i<n;i++)
        {
            long long area =a[i]*(r[i]-l[i]-1);
            if(i==0 ||ans <area)
                ans = area;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
