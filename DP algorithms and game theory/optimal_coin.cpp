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
#define N 105
ll coin[N], dp[N][N];

ll memo(ll i, ll j) {
  if (i > j) {
    return 0;
  } else if (dp[i][j] != -1) {
    return dp[i][j];
  } else if (i == j) {
    return dp[i][j] = coin[i];
  } else if (j == i + 1) {
    return dp[i][j] = max(coin[i], coin[j]);
  } else {
    ll k;
    return dp[i][j] = max(coin[i] + min(memo(i + 2, j), memo(i + 1, j - 1)),
                          coin[j] + min(memo(i + 1, j - 1), memo(i, j - 2)));
  }
}

int main() {
  ll t, n, i, j;
  sl(t);
  while (t--) {
    sl(n);
    fu(i, 1, n) { sl(coin[i]); }
    fu(i, 1, n) {
      fu(j, 1, n) { dp[i][j] = -1; }
    }
    pl(memo(1, n));
    pn();
  }
  return 0;
}