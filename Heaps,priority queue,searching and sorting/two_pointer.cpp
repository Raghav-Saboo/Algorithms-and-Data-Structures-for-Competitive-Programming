// Problem link http://www.spoj.com/problems/HOTELS/
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
#define N 300005
ll arr[N];

int main() {
  ll n, m;
  ll i, j, l, r;
  sl(n);
  sl(m);
  fu(i, 1, n) { sl(arr[i]); }
  ll ans = 0, cs = 0;
  l = 1;
  r = 1;
  while (l <= n) {
    while (r <= n && cs + arr[r] <= m) {
      cs += arr[r];
      r++;
    }
    ans = max(ans, cs);
    cs -= arr[l];
    l++;
  }
  pl(ans);
  pn();
  return 0;
}
