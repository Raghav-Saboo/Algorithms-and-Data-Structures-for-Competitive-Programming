// Problem link http://codeforces.com/gym/100814/problem/G
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
#define N 1000005
vector<pair<ll, pll> > adj[N];
ll vis[N];
ll dis[N];

ll predicate(ll src, ll x, ll n, ll cost) {
  ll i, j, u, c, w;
  multiset<pll> pq;
  fu(i, 1, n) {
    dis[i] = 1e10;
    vis[i] = 0;
  }
  dis[src] = 0;
  pq.insert(mp(dis[src], src));
  while (pq.size() > 0) {
    pll p = *(pq.begin());
    u = p.second;
    pq.erase(pq.begin());
    for (pair<ll, pll> tp : adj[u]) {
      if (!vis[tp.first] && dis[tp.first] > dis[u] + tp.second.first &&
          tp.second.second <= x) {
        dis[tp.first] = dis[u] + tp.second.first;
        pq.insert(mp(dis[tp.first], tp.first));
      }
    }
  }
  if (dis[n] < cost) {
    return 1;
  }
  return 0;
}

int main() {
  ll n, m, k, u, v, c, w;
  ll i, j, low, mid, high, ans;
  ll t;
  sl(t);
  while (t--) {
    sl(n);
    sl(m);
    sl(k);
    fu(i, 1, m) {
      sl(u);
      sl(v);
      sl(c);
      sl(w);
      adj[u].pb(mp(v, mp(c, w)));
      adj[v].pb(mp(u, mp(c, w)));
    }
    low = 1;
    high = 1e9;
    ans = -1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (predicate(1, mid, n, k)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    pl(ans);
    pn();
    fu(i, 1, n) { adj[i].clear(); }
  }
  return 0;
}