// Problem link http://www.spoj.com/problems/SUBMERGE/
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
ll fup[N];
ll tin[N];
ll par[N];
ll vis[N];
set<ll> ap;
set<pll> bridge;

void dfs(ll u, ll &ti, ll root) {
  ti = ti + 1;
  tin[u] = ti;
  vis[u] = 1;
  fup[u] = tin[u];
  ll i;
  ll child = 0;
  rep(i, adj[u].size()) {
    if (!vis[adj[u][i]]) {
      child++;
      par[adj[u][i]] = u;
      dfs(adj[u][i], ti, root);
      fup[u] = min(fup[u], fup[adj[u][i]]);
      if (fup[adj[u][i]] >= tin[u] && u != root) {
        // printf("***");ps();pl(u);ps();pl(fup[u]);pl(adj[u][i]);ps();pl(fup[adj[u][i]]);pn();
        ap.insert(u);
      }
      if (fup[adj[u][i]] > tin[u]) {
        if (u <= adj[u][i]) {
          bridge.insert(mp(u, adj[u][i]));
        } else {
          bridge.insert(mp(adj[u][i], u));
        }
      }
    } else if (vis[adj[u][i]] == 1 && adj[u][i] != par[u]) {
      fup[u] = min(fup[u], tin[adj[u][i]]);
    }
  }
  if (u == root && child > 1) {
    ap.insert(root);
  }
  vis[u] = 2;
}

int main() {
  ll n, m, i, u, v;
  while (1) {
    sl(n);
    sl(m);
    if (n == 0 || m == 0) {
      break;
    }
    fu(i, 1, m) {
      sl(u);
      sl(v);
      adj[u].pb(v);
      adj[v].pb(u);
    }
    ll ti = 0;
    fu(i, 1, n) {
      if (!vis[i]) {
        dfs(i, ti, i);
      }
    }
    // pl(ap.size());
    printf("%lu\n", ap.size());
    /*pn();
    set <ll> :: iterator it1;
    for(it1=ap.begin();it1!=ap.end();it1++)
    {
        pl(*it1);
        ps();
    }
    pn();
    //pl(bridge.size());
    printf("Caso #%lld\n",tn);
    tn++;
    if(bridge.size()==0)
    {
        printf("Sin bloqueos\n");
    }
    else
    {
        printf("%lu",bridge.size());
        pn();
        set <pll> :: iterator it2;
        for(it2=bridge.begin();it2!=bridge.end();it2++)
        {
            pl((*it2).first);ps();pl((*it2).second);
            pn();
        }
    }*/
    ap.clear();
    bridge.clear();
    fu(i, 1, n) {
      adj[i].clear();
      vis[i] = 0;
    }
  }
  return 0;
}