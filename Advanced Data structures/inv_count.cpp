//Problem link http://www.spoj.com/problems/INVCNT/
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
#define N 200005
ll arr[N];
ll bit[N];
void upd(ll id,ll v,ll n)
{
    while(id<=n)
    {
        bit[id]+=v;
        id+=(id&-id);
    }
}
ll query(ll id)
{
    ll s=0;
    while(id>0)
    {
        s+=bit[id];
        id-=(id&-id);
    }
    return s;
}
int main()
{
    ll n,i,j,ans,x,y,t;
    sl(t);
    while(t--)
    {
        ans=0;
        map <ll,ll> fp,rp;
        sl(n);
        fu(i,1,n)
        {
            sl(arr[i]);
            fp[arr[i]]++;
        }
        i=0;
        for(map<ll,ll>::iterator it=fp.begin();it!=fp.end();it++)
        {
            rp[it->first]=++i;
        }
        fu(i,1,n)
        {
            arr[i]=rp[arr[i]];
        }
        ans=0;
        fd(i,n,1)
        {
            ans+=query(arr[i]-1);
            upd(arr[i],1,n);
        }
        fu(i,1,n)
        {
            bit[i]=0;
        }
        pl(ans);
        pn();
    }
    return 0;
}