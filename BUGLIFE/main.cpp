#include <iostream>
#include <vector>

using namespace std;
int rep[2002];
vector<int> in[2002];
int main()
{
    int t;
    int tc=0;
    cin>>t;
    while(t--)
    {
        tc++;
        int n,m,i;
        cin>>n>>m;
        for(i=1;i<=n;i++)
            rep[i]=0,in[i].clear();
        for(i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a>b)
                swap(a,b);
            in[a].push_back(b);
        }
        bool flag=true;
        for(i=1;i<=n && flag;i++)
        {
            if(rep[i]==0)
                rep[i]=1;

            for(int x:in[i])
                if(rep[x]==rep[i])
                {
                    flag=false;
                    break;
                }
                else
                    rep[x]=3-rep[i];

        }
        cout<<"Scenario #"<<tc<<":\n";
        if(flag)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }
    return 0;
}
