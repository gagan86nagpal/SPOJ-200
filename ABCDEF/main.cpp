#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map <long long,long long> m1;
vector<long long> s;
int main()
{
    long long n;
    cin>>n;
    long long i,j,k;
    for(i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        s.push_back(x);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
            {
                long long c= s[i]*s[j] + s[k];
                m1[c]=m1[c]+1;
            }
    long long ans=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
            {
                if(s[k]==0)
                    continue;
                long long c=( s[i]+s[j] )* s[k];
                ans+=m1[c];
            }
    cout<<ans<<"\n";
    return 0;
}
