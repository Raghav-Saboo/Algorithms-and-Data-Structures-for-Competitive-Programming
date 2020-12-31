// Problem Link
// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-problem/
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
vector<pll> adj[N];
ll d[N];
ll vis[N];

struct cmp {
  bool operator()(const pll &a, const pll &b) { return a.second > b.second; }
};

void dij(ll src, ll n) {
  ll i;
  fu(i, 1, n) {
    d[i] = 1e9;
    vis[i] = 0;
  }
  priority_queue<pll, vector<pll>, cmp> pq;
  pq.push(mp(src, 0));
  d[src] = 0;
  while (!pq.empty()) {
    ll u = pq.top().first;
    pq.pop();
    for (pll pl : adj[u]) {
      ll v = pl.first;
      if (!vis[v] && d[v] > d[u] + pl.second) {
        d[v] = d[u] + pl.second;
        pq.push(mp(v, d[v]));
      }
    }
  }
}

int main() {
  ll n, m, u, v, i, w;
  sl(n);
  sl(m);
  fu(i, 1, m) {
    sl(u);
    sl(v);
    sl(w);
    adj[u].pb(mp(v, w));
  }
  ll src = 1;
  dij(src, n);
  fu(i, 2, n) {
    pl(d[i]);
    ps();
  }
  pn();
  return 0;
}