// GFG Practice
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
vector<ll> adj[N];
ll vis[N];
ll par[N];
set<ll> isc;

void dfs(ll u, ll p) {
  vis[u] = 1;
  par[u] = p;
  ll i;
  rep(i, adj[u].size()) {
    if (!vis[adj[u][i]]) {
      dfs(adj[u][i], u);
    } else if (vis[adj[u][i]] == 1) {
      isc.insert(u);
    }
  }
  vis[u] = 2;
}

int main() {
  ll n = 0, m, u, v, i;
  sl(n);
  sl(m);
  fu(i, 1, m) {
    sl(u);
    sl(v);
    adj[u].pb(v);
  }
  fu(i, 1, n) {
    if (!vis[i]) {
      dfs(i, -1);
    }
  }
  if (isc.size() > 0) {
    set<ll>::iterator it;
    for (it = isc.begin(); it != isc.end(); it++) {
      u = *it;
      v = par[u];
      i = 0;
      cout << u << " ";
      while (v != u && v != -1 && i < n) {
        i++;
        cout << v << " ";
        v = par[v];
      }
      cout << endl;
    }
  } else {
    printf("No cycle\n");
  }
  return 0;
}