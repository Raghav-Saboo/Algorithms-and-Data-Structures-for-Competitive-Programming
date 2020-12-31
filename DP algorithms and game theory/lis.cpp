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
ll dp[1005];
ll arr[N];

void lis(ll n) {
  ll i, j, ans = 1;
  fu(i, 1, n) { dp[i] = 1; }
  fu(i, 2, n) {
    fd(j, i - 1, 1) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    ans = max(ans, dp[i]);
  }
  pl(ans);
  pn();
}

int main() {
  ll t, n, i, x;
  sl(t);
  while (t--) {
    sl(n);
    fu(i, 1, n) { sl(arr[i]); }
    lis(n);
  }
  return 0;
}