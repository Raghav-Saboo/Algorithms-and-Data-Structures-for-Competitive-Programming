// Problem Link https://codeforces.com/contest/20/problem/C
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define fu(i, a, n) for (i = a; i <= n; i++)
#define fd(i, a, n) for (i = a; i >= n; i--)
#define rep(i, n) for (i = 0; i < n; i++)
#define si(i) scanf("%d", &i)
#define ss(s) scanf("%s", s)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define ps() printf(" ");
#define pn() printf("\n");
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vl vector<ll>
#define N 100005
ll uarr[N], varr[N], warr[N];
vector<ll> edj[N];
vector<pair<pll, ll> > ipedges;
struct cmp {
  bool operator()(pll a, pll b) { return a.se > b.se; }
};
priority_queue<pll, vector<pll>, cmp> pq;
set<pll> se;
ll vis[N];
ll par[N];
ll dis[N];
void dij(ll n) {
  ll i, j, src = 1, u, v, w;
  fu(i, 1, n) { dis[i] = 1e15; }
  dis[src] = 0;
  pq.push(mp(src, dis[src]));
  while (!pq.empty()) {
    pll p = pq.top();
    pq.pop();
    u = p.fi;
    vis[u] = 1;
    for (auto e : edj[u]) {
      v = uarr[e] ^ varr[e] ^ u;
      if (!vis[v] && dis[v] > dis[u] + warr[e]) {
        par[v] = u;
        dis[v] = dis[u] + warr[e];
        pq.push(mp(v, dis[v]));
      }
    }
  }
}
void print_path(ll u, ll src) {
  if (u == -1) return;
  if (u == src) {
    printf("%lld ", u);
    return;
  }
  print_path(par[u], src);
  printf("%lld ", u);
}
int main() {
  ll n, m, i, u, v, w;
  sl(n);
  sl(m);
  fu(i, 1, m) {
    sl(u);
    sl(v);
    sl(w);
    if (u != v) ipedges.pb(mp(mp(u, v), w));
  }
  sort(all(ipedges));
  i = 1;
  for (auto it : ipedges) {
    u = it.first.first;
    v = it.first.second;
    w = it.second;
    if (se.find(mp(u, v)) != se.end()) continue;
    se.insert(mp(u, v));
    uarr[i] = u;
    varr[i] = v;
    warr[i] = w;
    edj[u].pb(i);
    edj[v].pb(i);
    i++;
  }
  dij(n);
  if (!vis[n]) {
    printf("-1\n");
  } else {
    print_path(n, 1);
  }
  pn();
  return 0;
}