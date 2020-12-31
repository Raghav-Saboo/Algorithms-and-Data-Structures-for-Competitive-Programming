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
ll dp[N][N];

void edit_dis(string a, string b) {
  ll i, j, n, m;
  m = a.size();
  n = b.size();
  fu(i, 1, m) {
    fu(j, 1, n) { dp[i][j] = 0; }
  }
  fu(i, 1, m) { dp[i][0] = i; }
  fu(i, 1, n) { dp[0][i] = i; }
  fu(i, 1, m) {
    fu(j, 1, n) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
      }
    }
  }
  pl(dp[m][n]);
  pn();
}

int main() {
  ll t, n, m;
  string a, b;
  sl(t);
  while (t--) {
    cin >> n >> m >> a >> b;
    edit_dis(a, b);
  }
  return 0;
}