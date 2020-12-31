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
#define N 1005
ll dp[N][N], mod = 1e9 + 7;

void pre() {
  ll i, j;
  fu(i, 1, 1e3) {
    dp[i][0] = 1;
    dp[i][i] = 1;
  }
  fu(i, 1, 1e3) {
    fu(j, 1, i - 1) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      dp[i][j] %= mod;
    }
  }
}

int main() {
  pre();
  ll t, n, r;
  sl(t);
  while (t--) {
    sl(n);
    sl(r);
    cout << dp[n][r] << endl;
  }
  return 0;
}