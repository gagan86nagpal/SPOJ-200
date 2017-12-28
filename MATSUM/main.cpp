#include <iostream>

using namespace std;
long long mat[1030][1030];
long long bit[1030][1030];


void update(long long x,long long y,long long n,long long m ,long long v)
{
   long long i,j;
   for(i=x;i<=n;i+= (i&-i))
   {
       for(j=y ; j<=m ; j+=(j&-j))
            bit[i][j]+=v;
   }
}
 long long query(long long x,long long y,long long n,long long m)
{
    long long ans=0;
    if(x==0 || y==0)
        return 0;
    long long i,j;
   for(i=x;i>0;i-= (i&-i))
   {
       for(j=y ; j>0 ; j-=(j&-j))
            ans+=bit[i][j];
   }
   return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long i,j;
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                mat[i][j]=bit[i][j]=0;
        while(true)
        {
            string s;
            cin>>s;
            if(s[0]=='E')
                break;
            if(s[1]=='E') //set
            {
                long long x,y,v;
                cin>>x>>y>>v;
                x++;
                y++;
                long long temp = mat[x][y];
                mat[x][y]=v;
                v-=temp;
                update(x,y,n,n,v);
            }
            else
            {
                long long x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                x1++;
                y1++;
                x2++;
                y2++;
                long long ans = query(x2,y2,n,n) + query(x1-1,y1-1,n,n) - query(x1-1,y2,n,n) - query(x2,y1-1,n,n);
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
