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
#define N 10005
vector<pll> adj[N], residual[N];
ll flow[N][N], cf[N][N];
ll vis[N];
ll par[N];
set<pll> edge;

ll bfs(ll src, ll sink, ll n) {
  ll i;
  fu(i, 1, n) {
    par[i] = 0;
    vis[i] = 0;
  }
  queue<ll> q;
  q.push(src);
  vis[src] = 1;
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (pll pl : residual[u]) {
      ll v = pl.first;
      if (!vis[v]) {
        par[v] = u;
        vis[v] = 1;
        q.push(v);
      }
    }
    vis[u] = 2;
  }
  return vis[sink];
}

ll edmond_karp(ll src, ll sink, ll n) {
  ll i, j, ans;
  while (1) {
    fu(i, 1, n) {
      fu(j, 1, n) { cf[i][j] = 0; }
    }
    fu(i, 1, n) {
      for (pll pl : adj[i]) {
        ll v = pl.first;
        cf[i][v] = pl.second - flow[i][v];
        cf[v][i] = flow[i][v];
      }
    }
    fu(i, 1, n) {
      fu(j, 1, n) {
        if (cf[i][j] > 0) {
          residual[i].pb(mp(j, cf[i][j]));
        }
      }
    }
    if (bfs(src, sink, n) == 0) {
      break;
    }
    fu(i, 1, n) { residual[i].clear(); }
    ll cfp = 1e10;
    ll u = sink;
    while (u != src) {
      cfp = min(cfp, cf[par[u]][u]);
      u = par[u];
    }
    u = sink;
    while (u != src) {
      if (edge.find(mp(par[u], u)) == edge.end()) {
        flow[u][par[u]] -= cfp;
      } else {
        flow[par[u]][u] += cfp;
      }
      u = par[u];
    }
  }
  ans = 0;
  for (pll pl : adj[src]) {
    ans += flow[src][pl.first];
  }
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
    /*if(ssl.find(mp(a,b))!=ssl.end()&&ssl[mp(a,b)]<w)
    {
        ssl[mp(a,b)]=w;
    }
    else if(ssl.find(mp(a,b))==ssl.end())
    {
        ssl[mp(a,b)]=w;
    }*/
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
    edge.insert(mp(u, v));
  }
  ll src = si["A"];
  ll sink = si["Z"];
  pl(edmond_karp(src, sink, n));
  pn();
  return 0;
}