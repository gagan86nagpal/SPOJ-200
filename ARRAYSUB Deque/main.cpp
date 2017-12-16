#include <iostream>
#include <deque>
using namespace std;
int a[100002];
deque<int>dq;
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    for(i=0;i<k;i++)
    {
        while(!dq.empty() && a[i]>=a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    while(i<n)
    {
        cout<<a[dq.front()]<<" ";
         while(!dq.empty() && a[i]>=a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        i++;
    }
    cout<<a[dq.front()]<<"\n";
    return 0;
}
