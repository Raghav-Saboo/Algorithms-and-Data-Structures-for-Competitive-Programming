//Problem Link https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/dfs-3/
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
#define N 100005
vector<ll> adj[N];
ll vis[N];

void dfs(ll u) {
    vis[u] = 1;
    ll i;
    rep(i, adj[u].size()) {
        if (!vis[adj[u][i]]) {
            dfs(adj[u][i]);
        }
    }
}

int main() {
    ll n, m, u, v, i, src, ans = 0;
    sl(n);
    sl(m);
    fu(i, 1, m) {
        sl(u);
        sl(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sl(src);
    dfs(src);
    fu(i, 1, n) {
        if (!vis[i]) {
            ans++;
        }
    }
    pl(ans);
    pn();
    return 0;
}