// Problem Link https://www.codechef.com/problems/TSHIRTS
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
ll mod = 1e9 + 7;
ll dp[105][1 << N];
vector<ll> per[105];

ll rec(ll id, ll mask, ll n) {
  if (mask == (1 << n) - 1) {
    return dp[id][mask] = 1;
  }
  if (id > 100) {
    return 0;
  }
  if (dp[id][mask] != -1) {
    return dp[id][mask];
  }
  ll i, ans = 0;
  ans += rec(id + 1, mask, n);
  rep(i, per[id].size()) {
    if ((mask & (1 << (per[id][i] - 1))) == 0) {
      ans += rec(id + 1, mask | (1 << (per[id][i] - 1)), n);
      ans %= mod;
    }
  }
  return dp[id][mask] = ans;
}

int main() {
  char str[10005];
  ll t, n, i, x;
  sl(t);
  while (t--) {
    scanf("%lld\n", &n);
    fu(i, 1, n) {
      ll j, l;
      string s;
      while (s.size() == 0) {
        getline(cin, s);
      }
      l = s.size();
      x = 0;
      rep(j, l) {
        if (s[j] == ' ' && x > 0) {
          per[x].pb(i);
          x = 0;
        } else {
          x *= 10;
          x += s[j] - '0';
        }
      }
      per[x].pb(i);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = rec(1, 0, n);
    pl(ans);
    pn();
    fu(i, 1, 100) { per[i].clear(); }
  }
  return 0;
}