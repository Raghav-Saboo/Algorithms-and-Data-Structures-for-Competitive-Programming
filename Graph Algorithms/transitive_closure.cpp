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
ll dp[N][N], adj[N][N];

void transitive_closure(ll n) {
  ll i, j, k;
  fu(i, 1, n) {
    fu(j, 1, n) { dp[i][j] = adj[i][j]; }
  }
  fu(k, 1, n) {
    fu(i, 1, n) {
      fu(j, 1, n) {
        if (i == j) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
        }
      }
    }
  }
}

int main() {
  ll i, j;
  ll t, n;
  sl(t);
  while (t--) {
    sl(n);
    fu(i, 1, n) {
      fu(j, 1, n) { sl(adj[i][j]); }
    }
    transitive_closure(n);
    fu(i, 1, n) {
      fu(j, 1, n) { cout << dp[i][j] << " "; }
    }
    cout << endl;
  }
  return 0;
}