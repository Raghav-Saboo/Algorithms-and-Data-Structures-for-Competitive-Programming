//Problem Link https://codebuddy.co.in/problems/MAXXOR
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
#define N 18
ll dp[N][1<<N];
ll arr[N];
ll rec(ll id,ll n,ll mask)
{
	if(dp[id][mask]!=-1)
	{
		return dp[id][mask];
	}
	ll ans=0;
	ll i;
	fu(i,1,n)
	{
		if((mask&(1<<i))==0)
		{
			//cout<<mask<<" "<<id<<" "<<i<<" "<<(arr[id]^arr[i])<<" ** "<<endl;
			ans=max(ans,(arr[i]^arr[id])+rec(i,n,mask|(1<<i)));
		}
	}
	return dp[id][mask]=ans;
}
int main()
{
	ll n,i,j,l;
	string s;
	ll ans=0;
	sl(n);
	fu(i,1,n)
	{
		cin>>s;
		l=s.size();
		ll x=0;
		rep(j,l)
		{
			x+=s[j]-'a'+1;
		}
		arr[i]=x;
		//cout<<i<<" "<<arr[i]<<endl;
	}
	memset(dp,-1,sizeof(dp));
	fu(i,1,n)
	{
		//cout<<i<<" "<<rec(i,n,(1<<i))<<endl;
		ll val=rec(i,n,(1<<i));
		//cout<<i<<" "<<ld<<endl;
		ans=max(ans,val);
	}
	pl(ans);pn();
	return 0;
}