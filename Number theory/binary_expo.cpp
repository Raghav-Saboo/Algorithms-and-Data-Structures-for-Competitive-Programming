//Problem link http://www.spoj.com/problems/LASTDIG2/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=10;
ll mdstring(string s)
{
	ll i,ans=0;
	ll l=s.size();
	for(i=0;i<l;i++)
	{
		ans*=10;
		ans+=s[i]-'0';
		ans%=mod;
	}
	return ans;
}
ll mexp(string a,ll b)
{
	if(b==0)
	{
		return 1;
	}
	ll tmp=mexp(a,b/2);
	if(b%2==0)
	{
		return (tmp*tmp)%mod;
	}
	else
	{
		return (tmp*tmp*mdstring(a))%mod;
	}
}
int main()
{
	ll t,b;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s>>b;
		cout<<mexp(s,b)<<endl;
	}
	return 0;
}