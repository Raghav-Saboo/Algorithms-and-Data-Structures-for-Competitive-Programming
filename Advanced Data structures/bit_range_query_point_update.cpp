// Problem Link
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/akash-and-gcd-1-16/
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
#define N 1000005
ll arr[N];
ll f[N];
ll phi[N];
ll bit[N];
ll mod = 1e9 + 7;

void upd(ll id, ll v, ll n) {
  while (id <= n) {
    bit[id] += v;
    id += (id & -id);
  }
}

ll query(ll id) {
  ll s = 0;
  while (id > 0) {
    s += bit[id];
    s %= mod;
    id -= (id & -id);
  }
  return s;
}

void pre() {
  ll n = 1e6, i, j;
  fu(i, 1, n) { phi[i] = i; }
  fu(i, 1, n) {
    for (j = i * 2; j <= n; j += i) {
      phi[j] -= phi[i];
    }
  }
  fu(i, 1, n) {
    for (j = i; j <= n; j += i) {
      f[j] += i * phi[j / i];
    }
  }
}

int main() {
  pre();
  char ch;
  ll n, q, l, r, ans, i;
  sl(n);
  fu(i, 1, n) {
    sl(arr[i]);
    // cout<<arr[i]<<" "<<phi[arr[i]]<<" "<<f[arr[i]]<<endl;
    upd(i, f[arr[i]], n);
  }
  sl(q);
  while (q--) {
    cin >> ch;
    if (ch == 'C') {
      sl(l);
      sl(r);
      pl((query(r) - query(l - 1) + mod) % mod);
      pn();
    } else {
      sl(l);
      sl(r);
      upd(l, -f[arr[l]], n);
      arr[l] = r;
      upd(l, f[arr[l]], n);
    }
  }
  return 0;
}