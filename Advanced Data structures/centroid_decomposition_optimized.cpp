// Problem Link https://codeforces.com/contest/342/problem/E
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
#define mxlgn 30
ll uarr[N], varr[N];
vector<ll> edge[N];
ll par_centroid[N];
ll par[N];
ll sub_size[N];
ll level_centroid[N];
ll level[N];
ll ans[N];
ll dp[mxlgn][N];
ll deleted[N];
ll lca_dp[N][mxlgn];
ll adjacent_edge(ll e, ll u) { return uarr[e] ^ varr[e] ^ u; }

void pre_lca(ll n) {
  ll i, j;
  for (j = 1; (1 << j) < n; j++) {
    fu(i, 1, n) { lca_dp[i][j] = -1; }
  }
  fu(i, 1, n) { lca_dp[i][0] = par[i]; }
  for (j = 1; (1 << j) < n; j++) {
    fu(i, 1, n) {
      if (lca_dp[i][j - 1] != -1) {
        lca_dp[i][j] = lca_dp[lca_dp[i][j - 1]][j - 1];
      }
    }
  }
}
ll lca_query(ll u, ll v) {
  ll i, tmp, log1;
  if (level[u] < level[v]) {
    tmp = u;
    u = v;
    v = tmp;
  }
  log1 = 0;
  for (log1 = 1; (1 << log1) <= level[u]; log1++)
    ;
  log1--;
  for (i = log1; i >= 0; i--) {
    if (level[u] - (1 << i) >= level[v]) {
      u = lca_dp[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (i = log1; i >= 0; i--) {
    if (lca_dp[u][i] != -1 && lca_dp[u][i] != lca_dp[v][i]) {
      u = lca_dp[u][i];
      v = lca_dp[v][i];
    }
  }
  return par[u];
}
void dfs_pre_lca(ll u, ll p, ll lev) {
  level[u] = lev;
  par[u] = p;
  for (auto e : edge[u]) {
    ll v = adjacent_edge(e, u);
    if (v == p) continue;
    dfs_pre_lca(v, u, lev + 1);
  }
}
void dfs(ll u, ll p) {
  sub_size[u] = 1;
  for (auto e : edge[u]) {
    ll v = adjacent_edge(e, u);
    if (deleted[e] || v == p) continue;
    dfs(v, u);
    sub_size[u] += sub_size[v];
  }
}
ll find_centroid(ll u, ll p, ll n) {
  for (auto e : edge[u]) {
    ll v = adjacent_edge(e, u);
    if (!deleted[e] && v != p && sub_size[v] > n / 2) {
      return find_centroid(v, u, n);
    }
  }
  return u;
}
void delete_edges(ll centroid) {
  for (auto e : edge[centroid]) {
    deleted[e] = 1;
  }
}
void dfs2(ll u, ll p, ll lvl) {
  sub_size[u] = 1;
  for (auto e : edge[u]) {
    ll v = adjacent_edge(e, u);
    if (deleted[e] || v == p) continue;
    dp[lvl][v] = dp[lvl][u] + 1;
    dfs2(v, u, lvl);
  }
}
void add_edge_in_centroid_tree(ll child, ll parent) {
  par_centroid[child] = parent;
  level_centroid[child] = (parent == -1 ? 0 : level_centroid[parent]) + 1;
}
void decompose(ll u, ll p) {
  // Compute the subtree sizes
  dfs(u, p);
  // Find the centroid of the tree
  ll centroid = find_centroid(u, p, sub_size[u]);
  add_edge_in_centroid_tree(centroid, p);
  // Process all the paths from this centroid to all the leaves
  // Delete the adjacent edges and recursively find the remaining centroids of
  // the smaller trees
  dfs2(centroid, p, level_centroid[centroid]);
  for (auto e : edge[centroid]) {
    if (deleted[e]) continue;
    deleted[e] = 1;
    ll v = adjacent_edge(e, centroid);
    decompose(v, centroid);
  }
}
ll dist_orig(ll u, ll v) {
  ll lca = lca_query(u, v);
  return level[u] + level[v] - 2 * level[lca];
}
int main() {
  ll n, m, u, v, i, ty;
  sl(n);
  sl(m);
  fu(i, 1, n - 1) {
    sl(u);
    sl(v);
    uarr[i] = u;
    varr[i] = v;
    edge[u].pb(i);
    edge[v].pb(i);
  }
  dfs_pre_lca(1, -1, 1);
  pre_lca(n);
  decompose(1, -1);
  ans[1] = 0;
  fu(i, 2, n) { ans[i] = level[i] - level[1]; }
  while (m--) {
    sl(ty);
    sl(u);
    if (ty == 1) {
      ans[u] = 0;
      v = u;
      while (v != -1) {
        ans[v] = min(ans[v], dist_orig(u, v));
        v = par_centroid[v];
      }
    } else {
      ll mn = 1e10;
      v = u;
      while (v != -1) {
        mn = min(mn, ans[v] + dist_orig(u, v));
        v = par_centroid[v];
      }
      pl(mn);
      pn();
    }
  }
  return 0;
}