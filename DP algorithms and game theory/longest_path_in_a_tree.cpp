//Problem Link http://www.spoj.com/problems/PT07Z/ DP on Trees
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i, a, n) for(i=a;i<=n;i++)
#define fd(i, a, n) for(i=a;i>=n;i--)
#define rep(i, n)  for(i=0;i<n;i++)
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
#define N 10005
vector<ll> adj[N];
ll f[N], g[N], diameter, vis[N];

void dfs(ll V) {
    ll i;
    vector<ll> fv;
    vis[V] = 1;
    for (ll v:adj[V]) {
        if (!vis[v]) {
            dfs(v);
            fv.pb(f[v]);
        }
    }
    sort(all(fv));
    if (fv.size() > 0) {
        f[V] = 1 + fv[fv.size() - 1];
    }
    if (fv.size() > 1) {
        g[V] = 2 + fv[fv.size() - 1] + fv[fv.size() - 2];
    }
    //cout<<V<<" "<<f[V]<<" "<<g[V]<<endl;
    diameter = max(diameter, max(f[V], g[V]));
}

int main() {
    ll n, u, v, i;
    sl(n);
    rep(i, n - 1) {
        sl(u);
        sl(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    pl(diameter);
    pn();
    return 0;
}