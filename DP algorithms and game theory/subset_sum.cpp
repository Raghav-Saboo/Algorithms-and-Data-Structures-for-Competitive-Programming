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
ll dp[N][10005];
ll arr[N];
void issum(ll n,ll x)
{
    ll i,j,ans;
    //cout<<x<<endl;
    fu(i,1,n)
    {
        fu(j,1,x)
        {
            dp[i][j]=false;
        }
    }
    dp[0][0]=true;
    fu(i,1,n)
    {
        fu(j,1,x)
        {
            if(j-arr[i]>=0)
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][x])
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}
int main()
{
    ll t,n,i;
    sl(t);
    while(t--)
    {
        sl(n);
        ll x=0;
        fu(i,1,n)
        {
            sl(arr[i]);
            x+=arr[i];
        }
        if(x%2==0)
        {
            issum(n,x/2);
        }
        else
        {   
            cout<<"NO\n";
        }
    }
    return 0;
}