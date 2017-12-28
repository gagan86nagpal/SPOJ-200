#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector < pair < pair <int,int> ,int  > > boxes;

int dp[200][200];
bool compatible(pair < pair <int,int> ,int  > p1, pair < pair <int,int> ,int  > p2)
{
    return (p1.first.first > p2.first.first && p1.first.second > p2.first.second);
}
int solve(int i,int n,int pr=-1)
{
    if(dp[i][pr+1]!=-1)
        return dp[i][pr+1];
    if(i==n)
        return dp[i][pr+1]= 0;
    if(pr==-1 ||  compatible(boxes[i],boxes[pr]) )
        return dp[i][pr+1]= max(  solve(i+1,n,i)+ boxes[i].second , solve(i+1,n,pr) );
    else
        return dp[i][pr+1]= solve(i+1,n,pr);
}
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        boxes.clear();
        int i,j;
        for(i=0;i<=6*n+1;i++)
            for(j=0;j<=6*n+1;j++)
                dp[i][j]=-1;
        //boxes.push_back({{0,0},0});
        for(i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            boxes.push_back({{a,b},c});
            boxes.push_back({{a,c},b});
            boxes.push_back({{b,a},c});
            boxes.push_back({{b,c},a});
            boxes.push_back({{c,a},b});
            boxes.push_back({{c,b},a});
        }
        sort(boxes.begin(),boxes.end());
        int ans = solve(0,boxes.size());
        cout<<ans<<"\n";
    }
    return 0;
}
