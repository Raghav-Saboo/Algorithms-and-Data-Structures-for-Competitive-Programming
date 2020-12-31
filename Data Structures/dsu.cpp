// DSU Hackerearth practice
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
#define N 1005
ll par[N];
ll size[N];
multiset<ll> se;

ll fp(ll x) {
  if (x == par[x]) {
    return x;
  }
  return par[x] = fp(par[x]);
}

void uni(ll u, ll v) {
  ll pu, pv;
  pu = fp(u);
  pv = fp(v);
  if (par[pu] != pv) {
    par[pu] = pv;
    se.erase(se.find(size[pv]));
    size[pv] += size[pu];
    se.insert(size[pv]);
    se.erase(se.find(size[pu]));
  }
}

int main() {
  ll n, m, u, v, i;
  sl(n);
  sl(m);
  fu(i, 1, n) {
    par[i] = i;
    size[i] = 1;
    se.insert(size[i]);
  }
  while (m--) {
    sl(u);
    sl(v);
    uni(u, v);
    for (multiset<ll>::iterator it = se.begin(); it != se.end(); it++) {
      pl(*it);
      ps();
    }
    pn();
  }
  return 0;
}