// Problem Link
// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
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
vector<pll> adj[N];
ll key[N];
ll par[N];
ll vis[N];

struct cmp {
  bool operator()(const pll &a, const pll &b) { return a.second > b.second; }
};

void prim(ll n, ll &ans, ll r) {
  priority_queue<pll, vector<pll>, cmp> pq;
  ll i, u;
  fu(i, 1, n) {
    key[i] = 1e12;
    par[i] = -1;
    vis[i] = 0;
  }
  key[r] = 0;
  pq.push(mp(r, key[r]));
  while (!pq.empty()) {
    u = pq.top().first;
    pq.pop();
    vis[u] = 1;
    rep(i, adj[u].size()) {
      if (!vis[adj[u][i].first] && adj[u][i].second < key[adj[u][i].first]) {
        key[adj[u][i].first] = adj[u][i].second;
        par[adj[u][i].first] = u;
        pq.push(mp(adj[u][i].first, key[adj[u][i].first]));
      }
    }
  }
  fu(i, 1, n) { ans += key[i]; }
}

int main() {
  ll n, m, u, w, v, i, ans = 0;
  sl(n);
  sl(m);
  fu(i, 1, m) {
    sl(u);
    sl(v);
    sl(w);
    adj[u].pb(mp(v, w));
    adj[v].pb(mp(u, w));
  }
  prim(n, ans, 1);
  pl(ans);
  pn();
  return 0;
}