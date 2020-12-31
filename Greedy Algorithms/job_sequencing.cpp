// GFG Practice
#include <bits/stdc++.h>

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
#define N 505
using namespace std;
pll arr[N];
ll par[105];

int cmp(pll a, pll b) { return a.second > b.second; }

void make(ll n) {
  ll i;
  rep(i, n + 1) { par[i] = i; }
}

ll fp(ll x) {
  if (x == par[x]) {
    return x;
  }
  return par[x] = fp(par[x]);
}

void uni(ll u, ll v) { par[v] = u; }

int main() {
  ll t, n, i, j, x;
  sl(t);
  while (t--) {
    sl(n);
    ll mx = 0;
    rep(i, n) {
      sl(x);
      sl(arr[i].fi);
      sl(arr[i].se);
      mx = max(mx, arr[i].fi);
    }
    sort(arr, arr + n, cmp);
    make(mx);
    ll ans = 0;
    x = 0;
    rep(i, n) {
      ll avail = fp(arr[i].fi);
      if (avail > 0) {
        uni(avail - 1, avail);
        x++;
        ans += arr[i].se;
      }
    }
    pl(x);
    ps();
    pl(ans);
    pn();
  }
  return 0;
}