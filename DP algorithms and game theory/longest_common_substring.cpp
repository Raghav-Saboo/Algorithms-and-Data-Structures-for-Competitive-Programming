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
ll dp[105][105];

void lcs(string a, string b) {
  ll i, j, ans = 0;
  ll n = b.size();
  ll m = a.size();
  fu(i, 1, m) {
    fu(j, 1, n) { dp[i][j] = 0; }
  }
  ll l;
  fu(i, 1, m) {
    fu(j, 1, n) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      }
    }
  }
  pl(ans);
  pn();
}

int main() {
  string a, b;
  ll t, m, n;
  sl(t);
  while (t--) {
    cin >> m >> n;
    cin >> a >> b;
    lcs(a, b);
  }
  return 0;
}