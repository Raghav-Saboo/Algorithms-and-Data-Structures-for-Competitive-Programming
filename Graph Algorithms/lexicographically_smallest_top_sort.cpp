// Problem Link //Problem Link
// https://practice.geeksforgeeks.org/problems/topological-sort/1
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
ll indeg[N];

int main() {
  ll n, m, u, v, i;
  sl(n);
  sl(m);
  fu(i, 1, m) {
    sl(u);
    sl(v);
    adj[u].pb(v);
    indeg[v]++;
  }
  v = 0;
  while (v < n) {
    u = -1;
    fu(i, 1, n) {
      if (indeg[i] == 0) {
        u = i;
        v++;
        pl(i);
        ps();
        break;
      }
    }
    if (u == -1) {
      break;
    }
    indeg[u] = -1;
    rep(i, adj[u].size()) { indeg[adj[u][i]]--; }
  }
  pn();
  return 0;
}

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
ll indeg[N];

int main() {
  ll n, m, u, v, i;
  sl(n);
  sl(m);
  fu(i, 1, m) {
    sl(u);
    sl(v);
    adj[u].pb(v);
    indeg[v]++;
  }
  v = 0;
  while (v < n) {
    u = -1;
    fu(i, 1, n) {
      if (indeg[i] == 0) {
        u = i;
        v++;
        pl(i);
        ps();
        break;
      }
    }
    if (u == -1) {
      break;
    }
    indeg[u] = -1;
    rep(i, adj[u].size()) { indeg[adj[u][i]]--; }
  }
  pn();
  return 0;
}