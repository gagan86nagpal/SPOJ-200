#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <string> v;
vector< pair <int,int > >white;
vector<pair<int,int> > black;
int ans[185][185];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        v.clear();
        white.clear();
        black.clear();
        int i,j;
        for(i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j]=='0')
                    black.push_back({i,j});
                else
                    white.push_back({i,j});
            }
        }
        for(pair<int,int> b : black)
        {
            int min_dist=500;
            for(pair<int,int> w: white)
            {
                int dist = abs(b.first-w.first) + abs(b.second-w.second);
                if(dist<min_dist)
                    min_dist = dist;
            }
            ans[b.first][b.second]=min_dist;
        }
        for(pair<int,int> w: white)
            ans[w.first][w.second]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
