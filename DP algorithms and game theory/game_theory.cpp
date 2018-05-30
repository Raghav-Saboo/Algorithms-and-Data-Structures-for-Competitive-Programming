//Problem link  http://www.spoj.com/problems/VECTAR11/
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
#define N 1000005
ll dp[N];
void game()
{
    ll i,j;
    dp[1]=1;
    dp[3]=1;
    dp[4]=1;
    fu(i,3,1e6)
    {
        ll flag=0;
        for(j=1;j*j<=i;j++)
        {
            if(i-j*j>=0&&!dp[i-j*j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            dp[i]=1;
        }
    }
}
int main()
{
    ll t,n;
    sl(t);
    game();
    while(t--)
    {
        sl(n);
        if(dp[n])
        {
            printf("Win\n");
        }
        else
        {
            printf("Lose\n");
        }
    }
    return 0;
}