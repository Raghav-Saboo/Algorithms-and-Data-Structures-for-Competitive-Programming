//Problem Link https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
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
vector <pll> adj[N];
ll par[N];
struct edge
{
    ll u;
    ll v;
    ll w;
};
struct edge arr[N];
int cmp(struct edge a,struct edge b)
{
    return a.w<b.w;
}
void make_par(ll n)
{
    ll i;
    fu(i,1,n)
    {
        par[i]=i;
    }
}
ll fp(ll x)
{
    if(x==par[x])
    {
        return x;
    }
    return par[x]=fp(par[x]);
}
void uni(ll x,ll y,ll w,ll &ans)
{
    ll px,py;
    px=fp(x);
    py=fp(y);
    if(px!=py)
    {
        par[px]=py;
        ans+=w;
    }
}
int main()
{
    ll n,m,u,w,v,i,ans=0;
    sl(n);
    sl(m);
    fu(i,1,m)
    {
        sl(u);
        sl(v);
        sl(w);
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
        arr[i].u=u;arr[i].v=v;arr[i].w=w;
    }
    sort(arr+1,arr+1+m,cmp);
    make_par(n);
    fu(i,1,m)
    {
        uni(arr[i].u,arr[i].v,arr[i].w,ans);
    }
    pl(ans);
    pn();
    return 0;
}