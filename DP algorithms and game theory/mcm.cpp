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
#define N 505
ll dp[N][N];
ll dir[N][N];
ll p[N];
void print(ll i,ll j)
{
    if(j==i+1)
    {
        char a,b;
        a='A'+(i-1);
        b='A'+(j-1);
        cout<<"("<<a<<b<<")";
    }
    else if(i==j)
    {
        char a='A'+(i-1);
        cout<<a;
    }
    else if(i>=1&&j>=1)
    {
        cout<<"(";
        print(i,dir[i][j]);
        print(dir[i][j]+1,j);
        cout<<")";
    }
}
void mcm(ll n)
{
    ll i,j,k,l;
    fu(i,1,n)
    {
        fu(j,1,n)
        {
            dir[i][j]=0;
            dp[i][j]=1e10;
        }
    }
    fu(i,1,n)
    {
        dp[i][i]=0;
    }
    fu(i,1,n-1)
    {
        dp[i][i+1]=p[i-1]*p[i]*p[i+1];
    }
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            ll tmp=1e10;
            for(k=i;k<j;k++)
            {
                if(tmp>p[i-1]*p[k]*p[j]+dp[i][k]+dp[k+1][j])
                {
                    dir[i][j]=k;
                }
                tmp=min(tmp,p[i-1]*p[k]*p[j]+dp[i][k]+dp[k+1][j]);
            }
            dp[i][j]=tmp;
        }
    }
    print(1,n);
    pn();
    //pl(dp[1][n]);pn();
}
int main()
{
    ll t,n,i;
    sl(t);
    while(t--)
    {
        sl(n);
        rep(i,n)
        {
            sl(p[i]);
        }
        mcm(n-1);
    }
    return 0;
}