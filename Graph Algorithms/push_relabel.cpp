// Problem Link http://www.spoj.com/problems/MTOTALF/
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ll, double>
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
#define N 1005
vector<pll> adj[N];
vector<ll> neigh_ls[N], admis[N];
ll flow[N][N], cf[N][N];
ll c[N][N];
ll h[N];
ll e[N];
ll vis[N];
ll edge[N][N];

void initialize_preflow(ll src, ll n) {
  ll i;
  fu(i, 1, n) {
    h[i] = 0;
    e[i] = 0;
  }
  h[src] = n;
  for (pll pl : adj[src]) {
    flow[src][pl.first] = c[src][pl.first];
    e[pl.first] = c[src][pl.first];
    e[src] -= c[src][pl.first];
  }
}

ll push(ll u, ll n) {
  ll v;
  fu(v, 1, n) {
    if (edge[u][v] == 1) {
      cf[u][v] = c[u][v] - flow[u][v];
    } else if (edge[v][u] == 1) {
      cf[u][v] = flow[v][u];
    } else {
      cf[u][v] = 0;
    }
    if (e[u] > 0 && cf[u][v] > 0 && h[u] == h[v] + 1) {
      ll mn = min(e[u], cf[u][v]);
      if (edge[u][v] == 1) {
        flow[u][v] += mn;
      } else {
        flow[v][u] -= mn;
      }
      e[u] -= mn;
      e[v] += mn;
      return 1;
    }
  }
  return 0;
}

void relabel(ll u, ll n) {
  ll v, mn = 1e10;
  fu(v, 1, n) {
    if (edge[u][v] == 1) {
      cf[u][v] = c[u][v] - flow[u][v];
    } else if (edge[v][u] == 1) {
      cf[u][v] = flow[v][u];
    } else {
      cf[u][v] = 0;
    }
    if (cf[u][v] > 0 && h[u] <= h[v]) {
      mn = min(mn, h[v]);
    } else if (cf[u][v] > 0) {
      return;
    }
  }
  if (mn != 1e10) {
    h[u] = 1 + mn;
  }
}

ll overflow_vertex(ll src, ll sink, ll n) {
  ll i;
  fu(i, 1, n) {
    if (i != src && i != sink && e[i] > 0) {
      return i;
    }
  }
  return -1;
}

ll push_relabel(ll src, ll sink, ll n) {
  initialize_preflow(src, n);
  while (overflow_vertex(src, sink, n) != -1) {
    ll u = overflow_vertex(src, sink, n);
    if (!push(u, n)) {
      relabel(u, n);
    }
  }
  ll ans = 0, u;
  fu(u, 1, n) { ans += flow[src][u]; }
  return ans;
}

int main() {
  ll n, m, u, v, i, w;
  string a, b;
  sl(n);
  // sl(m);
  map<string, int> si;
  i = 0;
  map<pair<string, string>, ll> ssl;
  while (cin >> a) {
    cin >> b >> w;
    ssl[mp(a, b)] += w;
  }
  for (map<pair<string, string>, ll>::iterator it = ssl.begin();
       it != ssl.end(); it++) {
    a = it->first.first;
    b = it->first.second;
    w = it->second;
    if (si.find(a) == si.end()) {
      si[a] = ++i;
    }
    if (si.find(b) == si.end()) {
      si[b] = ++i;
    }
    u = si[a];
    v = si[b];
    adj[u].pb(mp(v, w));
    edge[u][v] = 1;
    neigh_ls[u].pb(v);
    neigh_ls[v].pb(u);
    c[u][v] = w;
  }
  ll src = si["A"];
  ll sink = si["Z"];
  pl(push_relabel(src, sink, n));
  pn();
  return 0;
}