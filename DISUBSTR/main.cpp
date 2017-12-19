#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string a;
struct suff
{
    int index;
    int r;
    int nr;
};
suff suffix[1002];
int suffix_array[1002];
int m[1002];
int lcp[1002];
bool cmp (suff  s1,suff  s2)
{
    if(s1.r == s2.r)
        return s1.nr < s2.nr;
    return s1.r<s2.r;
}
void build_array(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        suffix[i].index=i;
        suffix[i].r = a[i];
        suffix[i].nr = (i+1<n)?(a[i+1]):-1;
    }
    sort(suffix,suffix+n,cmp);
    for(int k=4;k<2*n ; k*=2)
    {
        int prev_rank = suffix[0].r;
        suffix[0].r=0;
        m[suffix[0].index] = 0;
        for(i=1;i<n;i++)
        {
            if(prev_rank==suffix[i].r && suffix[i-1].nr == suffix[i].nr)
                suffix[i].r = suffix[i-1].r;
            else
            {
                prev_rank = suffix[i].r;
                suffix[i].r  =  1+suffix[i-1].r;
            }
            m[suffix[i].index]=i;
        }
        for(i=0;i<n;i++)
        {
            int in = suffix[i].index + k/2;
            if(in<n)
                suffix[i].nr = suffix[m[in]].r;
            else
                suffix[i].nr =-1;
        }
        sort(suffix,suffix+n,cmp);
    }
    for(i=0;i<n;i++)
        suffix_array[i]=suffix[i].index;

    for(i=0;i<n;i++)
        m[suffix_array[i]]=i;
    int k=0;

    for(i=0;i<n;i++)
    {
        if(m[i]==n-1)
        {
            k=0;
            continue;
        }
        int j  =  suffix_array[m[i]+1];
        while(i+k < n && j+k<n && a[i+k]==a[j+k])
            k++;
        lcp[m[i]]=k;
        if(k>0)
            k--;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            suffix[i]={0,0,0};
            suffix_array[i]=0;
            m[i]=0;
            lcp[i]=0;
        }
        build_array(n);
        int ans = n*(n+1);
        ans/=2;
        for(int i=0;i<n;i++)
            ans-=lcp[i];
        cout<<ans<<"\n";
    }
    return 0;
}
