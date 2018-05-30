//Problem link  http://www.spoj.com/problems/TRIPINV/
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
#define N 100005
ll arr[N];
ll bit1[N];
ll bit2[N];
ll small[N],great[N];
void upd1(ll id,ll v,ll n)
{
    while(id<=n)
    {
        bit1[id]+=v;
        id+=(id&-id);
    }
}
ll query1(ll id)
{
    ll s=0;
    while(id>0)
    {
        s+=bit1[id];
        id-=(id&-id);
    }
    return s;
}
void upd2(ll id,ll v,ll n)
{
    while(id<=n)
    {
        bit2[id]+=v;
        id+=(id&-id);
    }
}
ll query2(ll id)
{
    ll s=0;
    while(id>0)
    {
        s+=bit2[id];
        id-=(id&-id);
    }
    return s;
}
int main()
{
    ll n,i,j,ans,x,y;
    sl(n);
    fu(i,1,n)
    {
        sl(arr[i]);
    }
    ans=0;
    fd(i,n,1)
    {
        small[i]=query1(arr[i]-1);
        upd1(arr[i],1,n);
    }
    fu(i,1,n)
    {
        great[i]=(i-1)-query2(arr[i]);
        upd2(arr[i],1,n);
    }
    fu(i,1,n)
    {
        ans+=small[i]*great[i];
    }
    pl(ans);
    pn();
    return 0;
}