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
ll dp[1005][1005];

void lps(string s) {
  ll i, j, ans = 1;
  ll n = s.size();
  fu(i, 1, n) {
    fu(j, 1, n) { dp[i][j] = 0; }
  }
  fu(i, 1, n) { dp[i][i] = 1; }
  ll l;
  fu(l, 2, n) {
    fu(i, 1, n - l + 1) {
      j = i + l - 1;
      if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1] == (j - 1 - i)) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      }
    }
  }
  ans = 0;
  string ss;
  fu(i, 1, n) {
    fu(j, 1, n) {
      if (dp[i][j] > ans) {
        ans = dp[i][j];
        ss = s.substr(i - 1, dp[i][j]);
      }
    }
  }
  ans = dp[1][n];
  cout << ss;
  pn();
}

int main() {
  string s;
  ll t;
  sl(t);
  while (t--) {
    cin >> s;
    lps(s);
  }
  return 0;
}