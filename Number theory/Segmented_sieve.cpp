// Problem Link http://www.spoj.com/problems/PRIME1/
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
#define N 100005
using namespace std;
vector<ll> pr;
ll arr[N], mark[N];

void pre() {
  ll i, j;
  fu(i, 2, 1e5) {
    pr.pb(i);
    if (!arr[i]) {
      for (j = i * i; j <= 1e5; j += i) {
        arr[j] = 1;
      }
    }
  }
}

void get_pr(ll low, ll high) {
  ll i, j;
  fu(i, 0, high - low + 1) { mark[i] = 0; }
  if (low == 1) {
    mark[0] = 1;
  }
  rep(i, pr.size()) {
    if (pr[i] > high) {
      break;
    }
    ll sl = (low / pr[i]) * pr[i];
    if (sl < low) {
      sl += pr[i];
    }
    if (sl < 1e5 && !arr[sl]) {
      sl *= 2;
    }
    for (j = sl; j <= high; j += pr[i]) {
      mark[j - low] = 1;
    }
  }
  fu(i, low, high) {
    if (!mark[i - low]) {
      pl(i);
      pn();
    }
  }
  pn();
}

int main() {
  pre();
  ll t, l, r;
  sl(t);
  while (t--) {
    sl(l);
    sl(r);
    get_pr(l, r);
  }
  return 0;
}