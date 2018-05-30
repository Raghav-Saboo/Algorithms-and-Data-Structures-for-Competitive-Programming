//GFG Practice
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
#define N 25
using namespace std;
ll adj[N][N],path[N];
bool issafe(ll pos,ll v)
{
	ll i;
	fu(i,1,pos)
	{
		if(path[i]==v)
		{
			return false;
		}
	}
	if(pos>1&&adj[path[pos-1]][v]!=1)
	{
		return false;
	}
	//cout<<pos<<" "<<path[pos-1]<<" "<<v<<endl;
	return true;
}
ll hamiltonian_path(ll n,ll pos)
{
	if(pos==n+1)
	{
		return 1;
	}
	ll i;
	fu(i,1,n)
	{
		if(issafe(pos,i))
		{
			path[pos]=i;
			if(hamiltonian_path(n,pos+1))
			{
				return 1;
			}
			path[pos]=0;
		}
	}
	return 0;
}
int main()
{
	ll t,n,m,i,j;
	sl(t);
	while(t--)
	{
		sl(n);sl(m);
		fu(i,1,n)
		{
			path[i]=0;
			fu(j,1,n)
			{
				adj[i][j]=0;
			}
		}
		while(m--)
		{
			ll u,v;
			sl(u);sl(v);
			adj[u][v]=adj[v][u]=1;
		}
		pl(hamiltonian_path(n,1));pn();
	}
	return 0;
}