// Problem Link
// https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/practice-problems/algorithm/hamiltonian-path/
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
#define N 12
ll adj[N][N];
ll dp[1 << N][N];

void hamiltonian(ll n) {
  ll i, j, k, ans;
  rep(i, (1 << n)) {
    rep(j, n) { dp[i][j] = 0; }
  }
  rep(i, n) { dp[1 << i][i] = 1; }
  rep(i, (1 << n)) {
    rep(j, n) {
      if (i & (1 << j)) {
        rep(k, n) {
          if (k != j && (i & (1 << k)) && adj[k][j] && dp[i ^ (1 << j)][k]) {
            dp[i][j] = 1;
            break;
          }
        }
      }
    }
  }
  ans = 0;
  rep(i, n) {
    if (dp[(1 << n) - 1][i]) {
      ans = 1;
      break;
    }
  }
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ll n, m, u, v;
  sl(n);
  sl(m);
  while (m--) {
    sl(u);
    sl(v);
    adj[u][v] = adj[v][u] = 1;
  }
  hamiltonian(n);
  return 0;
}