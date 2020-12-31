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
#define N 1000005
using namespace std;
ll num[N], rem[N], pp[N], inv[N];

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  ll x1, y1;
  ll g = extended_euclid(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}

bool linear_diophantine(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
  ll x0, y0;
  g = extended_euclid(a, b, x0, y0);
  if (c % g) {
    return false;
  }
  x = x0 * c / g;
  y = y0 * c / g;
  if (a < 0) {
    x *= -1;
  }
  if (b < 0) {
    y *= -1;
  }
  return true;
}

int main() {
  ll t, k, i, prod, x, y, g;
  sl(t);
  while (t--) {
    sl(k);
    rep(i, k) { sl(num[i]); }
    rep(i, k) { sl(rem[i]); }
    prod = 1;
    rep(i, k) { prod *= num[i]; }
    rep(i, k) {
      pp[i] = prod / num[i];
      if (linear_diophantine(pp[i], num[i], 1, x, y, g)) {
        inv[i] = (x % num[i] + num[i]) % num[i];
      }
    }
    x = 0;
    rep(i, k) {
      x += rem[i] * pp[i] * inv[i];
      x %= prod;
    }
    rep(i, k) {
      pl(pp[i]);
      ps();
      pl(inv[i]);
      pn();
    }
    pl(x);
    pn();
  }
  return 0;
}