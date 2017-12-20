#include <iostream>
#include <vector>
using namespace std;
int m[100002];
vector< int>v ;

int solve(int n)
{
    int i;
    for(i=1;i<=n;i++)
        m[i]=1;
    i=1;
    int cnt=n;
    while(true)
    {
        if(cnt==1)
            break;
        while(m[i]!=1)
      {
          i++;
          if(i==n+1)
            i=1;
      }
      i++;
      if(i==n+1)
        i=1;
      while(m[i]!=1)
      {
          i++;
          if(i==n+1)
            i=1;
      }
      m[i]=0;
    cnt--;

    }
    i=1;
    while(m[i]!=1)
        i++;
    return i;
}
int main()
{
    int i;
    for(i=1;i<=100000000;i=i*2+1)
        v.push_back(i);
    while(true)
    {
        string s;
        cin>>s;
        if(s=="00e0")
            break;
        int n =(s[0]-'0')*10 + (s[1]-'0');
        int e = s[3]-'0';
        while(e--)
            n*=10;
        for(i=0;i<v.size();i++)
            if(v[i]>n)
                break;
        i--;
        int d= n-v[i];
        int ans;
        if(d==0)
            ans = n;
        else
            ans =2*d-1;
        cout<<ans<<"\n";
    }
    return 0;
}
