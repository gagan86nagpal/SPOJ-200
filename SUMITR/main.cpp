#include <bits/stdc++.h>
using namespace std;long long a[102][102],t,n,i,j,ans;main(){cin>>t;while(t--){cin>>n,ans=0;for(i=1;i<=n;i++)for(j=1;j<=i;j++)cin>>a[i][j],a[i][j]+=max(a[i-1][j],a[i-1][j-1]),ans=max(ans,a[i][j]);cout<<ans<<"\n";}return 0;}
