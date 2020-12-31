// Problem Link https://www.codechef.com/problems/TYTACTIC
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
using namespace std;
vector<ll> adj[N];
ll bit[N];
ll arr[N];
ll vis[N];
ll startt[N], endt[N];
ll gc;

void update(ll id, ll v, ll n) {
  while (id <= n) {
    bit[id] += v;
    id += (id & -id);
  }
}

ll query(ll id) {
  ll s = 0;
  // cout<<endl;
  while (id > 0) {
    s += bit[id];
    // cout<<id<<" "<<bit[id]<<" **"<<endl;
    id -= (id & -id);
  }
  return s;
}

void dfs(ll u, ll n) {
  vis[u] = 1;
  startt[u] = ++gc;
  update(gc, arr[u], n);
  for (ll v : adj[u]) {
    if (!vis[v]) {
      dfs(v, n);
    }
  }
  endt[u] = gc;
}

int main() {
  ll n, q, u, v;
  ll i, j;
  sl(n);
  sl(q);
  fu(i, 1, n) { sl(arr[i]); }
  fu(i, 1, n - 1) {
    sl(u);
    sl(v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, n);
  while (q--) {
    char ch;
    cin >> ch;
    if (ch == 'Q') {
      sl(u);
      // cout<<"4 "<<bit[4]<<endl;
      // cout<<endt[u]<<" "<<startt[u]<<" "<<query(startt[u]-1)<<"
      // "<<query(endt[u])<<" "<<u<<endl;
      pl(query(endt[u]) - query(startt[u] - 1));
      pn();
    } else if (ch == 'U') {
      sl(u);
      sl(v);
      update(startt[u], -arr[u], n);
      arr[u] = v;
      update(startt[u], arr[u], n);
    }
  }
  return 0;
}