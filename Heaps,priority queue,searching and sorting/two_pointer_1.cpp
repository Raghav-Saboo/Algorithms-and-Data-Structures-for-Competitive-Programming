// Problem link http://codeforces.com/problemset/problem/371/E
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
ll cum[N];
map<ll, ll> ind;

int main() {
  ll n, k, l, r, i, j, ans;
  ll st, en;
  sl(n);
  fu(i, 1, n) {
    sl(arr[i]);
    ind[arr[i]] = i;
  }
  sl(k);
  sort(arr + 1, arr + 1 + n);
  fu(i, 1, n) { cum[i] = cum[i - 1] + arr[i]; }
  ans = 0;
  l = 1;
  r = 2;
  ll sum = 0;
  while (r <= k) {
    // cout<<arr[r]<<" "<<(r-l)<<" "<<cum[r-1]<<" "<<cum[l-1]<<endl;
    sum += arr[r] * (r - l) - (cum[r - 1] - cum[l - 1]);
    r++;
  }
  ans = sum;
  st = 1;
  en = k;
  // cout<<ans<<endl;
  while (r <= n) {
    sum -= (cum[r - 1] - cum[l]) - (arr[l] * (r - l - 1));
    l++;
    sum += (arr[r] * (r - l)) - (cum[r - 1] - cum[l - 1]);
    // cout<<sum<<endl;
    if (ans > sum) {
      st = l;
      en = r;
      ans = sum;
    }
    r++;
  }
  fu(i, st, en) {
    pl(ind[arr[i]]);
    ps();
  }
  pn();
  return 0;
}