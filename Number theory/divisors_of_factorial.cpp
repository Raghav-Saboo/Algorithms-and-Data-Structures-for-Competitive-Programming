// Problem Link http://www.spoj.com/problems/DIVFACT/
#include <bits/stdc++.h>

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
#define N 50005
using namespace std;
ll arr[N];
ll mod = 1e9 + 7;
vector<ll> pr;

void pre() {
  ll i, j;
  fu(i, 2, 50000) {
    if (!arr[i]) {
      for (j = i * i; j <= 50000; j += i) {
        arr[j] = 1;
      }
    }
  }
  fu(i, 2, 50000) {
    if (!arr[i]) {
      pr.pb(i);
    }
  }
}

ll get(ll n) {
  ll i, ans = 1;
  ll cnt = 0;
  ll j;
  for (i = 0; i < pr.size() && pr[i] <= n; i++) {
    cnt = 0;
    for (j = n / pr[i]; j >= 1; j /= pr[i]) {
      cnt += j;
    }
    ans *= (cnt + 1);
    ans %= mod;
  }
  return ans;
}

int main() {
  pre();
  ll t, n;
  sl(t);
  while (t--) {
    sl(n);
    pl(get(n));
    pn();
  }
  return 0;
}