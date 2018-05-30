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
#define N 3005
ll dp[N][N];
ll wt[N],val[N];
void knapsack(ll cap,ll n)
{
    ll ans=0,i,j;
    fu(i,1,cap)
    {
        dp[0][i]=0;
    }
    fu(i,1,n)
    {
        fu(j,1,cap)
        {
            if(j-wt[i]>=0)
            {
                dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    ans=dp[n][cap];
    pl(ans);pn();
}
int main()
{
    ll cap,n,i;
    sl(cap);sl(n);
    fu(i,1,n)
    {
        sl(wt[i]);sl(val[i]);
    }
    knapsack(cap,n);
    return 0;
}