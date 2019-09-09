// https://www.codechef.com/problems/CATS
#include <bits/stdc++.h>
using namespace std;
#define ll int
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
#define sl(i)  scanf("%d",&i)
#define pi(i)  printf("%d",i)
#define pl(i)  printf("%d",i);
#define ps()   printf(" ");
#define pn()   printf("\n");
#define all(v)  v.begin(),v.end()
#define vi vector <int>
#define vl vector <ll>
using namespace std;
#define N 1000005
vector <ll> adj[N];
ll arr[N];
ll vis[N];
ll dp[N][25];
ll cat[N];
ll par[N];
ll lev[N];
void dfs(ll u,ll pr,ll lv)
{
	vis[u]=1;
	par[u]=pr;
	lev[u]=lv;
	for(ll v:adj[u])
	{
		if(!vis[v])
		{
			dfs(v,u,lv+1);
		}
	}
}
void pre_lca(ll n)
{
	ll i,j;
	fu(i,1,n)
	{
		dp[i][0]=par[i];
	}
	fu(j,1,20)
	{
		fu(i,1,n)
		{
			if(dp[i][j-1])
			{
				dp[i][j]=dp[dp[i][j-1]][j-1];
			}
		}
	}
}
ll cal(ll u)
{
	ll ans=0;
	ll i,v=u;
	if(cat[u])return ans;
	fd(i,20,0)
	{
		if(dp[v][i]&&!cat[dp[v][i]])
		{
			v=dp[v][i];
		}
	}
	cat[v]=1;
	ans=lev[u]-lev[v]+1;
	return ans;
}
int main()
{
	ll n,i,j,x,u,v,ans,root=0;
	sl(n);
	fu(i,1,n)
	{
		sl(x);
		if(x==0)
		{
			root=i;
		}
		else
		{
			adj[x].pb(i);
		}
	}
	fu(i,1,n)
	{
		sl(arr[i]);
	}
	dfs(root,0,0);
	pre_lca(n);
	fu(i,1,n)
	{
		vis[i]=0;
	}
	fu(i,1,n)
	{
		ans=cal(arr[i]);
		pl(ans);pn();
		u=arr[i];
	}
	return 0;
}