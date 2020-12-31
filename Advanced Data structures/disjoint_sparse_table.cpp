// Problem Link https://www.codechef.com/problems/SEGPROD
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
#define N 1048576
#define MXLEV 21
int arr[N];
int dp[MXLEV][N];
int b[N];
int p;

void build(int lev, int l, int r) {
  int m = (l + r) / 2;
  dp[lev][m] = arr[m] % p;
  int i;
  fd(i, m - 1, l) { dp[lev][i] = ((long long)dp[lev][i + 1] * arr[i]) % p; }
  if (m + 1 < r) {
    dp[lev][m + 1] = arr[m + 1] % p;
    fu(i, m + 2, r - 1) {
      dp[lev][i] = ((long long)dp[lev][i - 1] * arr[i]) % p;
    }
  }
  if (r - l > 1) {
    build(lev + 1, l, m);
    build(lev + 1, m, r);
  }
}

int query(int maxlev, int x, int y) {
  if (x == y) {
    return arr[x] % p;
  }
  int k2 = __builtin_clz(x ^ y) ^ 31;
  int lev = maxlev - k2 - 1;
  int ans = dp[lev][x];
  if (y & ((1 << k2) - 1)) {
    ans = ((long long)ans * dp[lev][y]) % p;
  }
  return ans;
}

int main() {
  int t, n, q, i, j, l, r, ans, size, maxlev, x, oq;
  int cnst = (1 << 6) - 1;
  si(t);
  while (t--) {
    si(n);
    si(p);
    si(q);
    oq = q;
    rep(i, n) { si(arr[i]); }
    q = (q >> 6) + 2;
    x = 0;
    rep(i, q) { si(b[i]); }
    size = n;
    maxlev = __builtin_clz(n) ^ 31;
    if ((1 << maxlev) != n) {
      size = (1 << (++maxlev));
    }
    fu(i, n, size - 1) { arr[i] = 1; }
    build(0, 0, size);
    ans = 0;
    l = 0;
    r = 0;
    // n=size;
    rep(i, oq) {
      if ((i & cnst) == 0) {
        l = (b[i >> 6] + x) % n;
        r = (b[(i >> 6) + 1] + x) % n;
      } else {
        l = (l + x) % n;
        r = (r + x) % n;
      }
      if (l > r) {
        j = l;
        l = r;
        r = j;
      }
      ans = query(maxlev, l, r);
      // cout<<l<<" "<<r<<" "<<ans<<endl;
      ans = (ans + 1) % p;
      x = ans;
    }
    pi(x);
    pn();
  }
  return 0;
}