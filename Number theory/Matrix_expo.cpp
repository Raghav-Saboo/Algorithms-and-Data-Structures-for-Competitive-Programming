//Problem Link https://www.hackerearth.com/problem/algorithm/q8/
#include <bits/stdc++.h>
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
using namespace std;
ll mod=1e9+7;
void mul(ll a[5][5],ll b[5][5],ll c[5][5])
{
	ll i,j,k;
	rep(i,5)
	{
		rep(j,5)
		{
			c[i][j]=0;
			rep(k,5)
			{
				c[i][j]+=(a[i][k]%mod)*(b[k][j]%mod);
				c[i][j]%=mod;
			}
		}
	}
}
void matrix_expo(ll a[5][5],ll b,ll ans[5][5])
{
	if(b==0)
	{
		ll i,j;
		rep(i,5)
		{
			rep(j,5)
			{
				if(i==j)
				{
					ans[i][j]=1;
				}
				else
				{
					ans[i][j]=0;
				}
			}
		}
		return;
	}
	ll tmp[5][5],i,j;
	matrix_expo(a,b/2,tmp);
	if(b%2==0)
	{
		mul(tmp,tmp,ans);
	}
	else
	{
		mul(tmp,tmp,ans);
		mul(ans,a,tmp);
		rep(i,5)
		{
			rep(j,5)
			{
				ans[i][j]=tmp[i][j];
			}
		}
	}
}
int main()
{	
	ll t,n,a,b,k,ans,i,x,y,j,kl;
	sl(t);
	while(t--)
	{
		sl(a);sl(b);sl(k);sl(n);
		ll am[5][5]={{1,1,-1,1,1},{0,1,-1,1,1},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};
		ll tmp1[5][1]={{a+b},{b},{a},{2*k},{k}};
		ll tmp2[5][1];
		ll ansm[5][5];
		if(n==2)
		{
			ans=b;
		}
		else if(n==1)
		{
			ans=a;
		}
		else
		{
			matrix_expo(am,n-2,ansm);
			rep(i,5)
			{
				rep(j,1)
				{
					tmp2[i][j]=0;
					rep(kl,5)
					{
						tmp2[i][j]+=(ansm[i][kl]%mod)*(tmp1[kl][j]%mod);
						tmp2[i][j]%=mod;
					}
				}
			}
			ans=tmp2[0][0];
		}
		pl(ans);pn();
	}
	return 0;
}