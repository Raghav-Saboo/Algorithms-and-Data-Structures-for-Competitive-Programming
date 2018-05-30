//GFG Practice
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,a,n) for(i=a;i>=n;i--)
#define rep(i,n)  for(i=0;i<n;i++)
#define si(i)  scanf("%d",&i)
#define ss(s)  scanf("%s",s)
#define sl(i)  scanf("%lld",&i)
#define pi(i)  printf("%d",i)
#define pl(i)  printf("%lld",i);
#define ps()   printf(" ");
#define pn()   printf("\n");
#define all(v)  v.begin(),v.end()
#define vi vector <int>
#define vl vector <ll>
#define N 105
ll dp[N][N];
void egg_drop(ll n,ll K)
{
    ll i,j,k,r;
    ll ans;
    fu(i,1,K)
    {
        dp[1][i]=i;
    }
    fu(i,1,n)
    {
        dp[i][1]=1;
    }
    fu(i,2,n)
    {
        fu(k,2,K)
        {
            j=1e10;
            fu(r,1,k)
            {
                j=min(j,max(dp[i-1][r-1],dp[i][k-r]));
            }
            dp[i][k]=1+j;
            //cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
        }
    }
    ans=dp[n][K];
    pl(ans);pn();
}
int main()
{
    ll t,n,i,k;
    sl(t);
    while(t--)
    {
        sl(n);sl(k);
        egg_drop(n,k);
    }
    return 0;
}