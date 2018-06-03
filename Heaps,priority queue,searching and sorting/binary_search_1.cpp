//Problem link https://www.codechef.com/problems/GCDMAX1
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
ll arr[N];
ll suff[N];
ll pref[N];
ll gcd(ll a,ll b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
ll predicate(ll x,ll n,ll k)
{
	ll i,j,c;
	for(i=1;i<=n;i+=x)
	{
		j=i+1;
		c=1;
		pref[i]=arr[i];
		fu(c,2,x)
		{
			pref[j]=gcd(pref[j-1],arr[j]);
			j++;
		}
		suff[i+x-1]=arr[i+x-1];
		j=i+x-2;
		fu(c,2,x)
		{
			suff[j]=gcd(suff[j+1],arr[j]);
			j--;
		}
	}
	fu(i,1,n-x+1)
	{
		if(gcd(suff[i],pref[i+x-1])>=k)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	ll low,mid,high,ans=0,i,j,n,k;
	sl(n);sl(k);
	fu(i,1,n)
	{
		sl(arr[i]);
	}
	low=1;
	high=n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(predicate(mid,n,k))
		{
			ans=mid;
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	pl(ans);pn();
	return 0;
}
