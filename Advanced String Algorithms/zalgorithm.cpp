// Problem link
// https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/practice-problems/algorithm/count-occurrences/
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
#define N 100005
ll z[N];

void z_algo(string txtcp, ll m) {
  ll i, l, r, ans = 0;
  ll n = txtcp.size();
  l = r = 0;
  z[0] = 0;
  fu(i, 1, n - 1) {
    if (i > r) {
      l = r = i;
      while (r < n && txtcp[r] == txtcp[r - l]) {
        r++;
      }
      z[i] = r - l;
      r--;
    } else {
      ll k = i - l;
      if (z[k] < r - i + 1) {
        z[i] = z[k];
      } else {
        l = r = i;
        while (r < n && txtcp[r] == txtcp[r - l]) {
          r++;
        }
        z[i] = r - l;
        r--;
      }
    }
  }
  fu(i, 1, n - 1) {
    if (z[i] == m) {
      ans++;
    }
  }
  pl(ans);
  pn();
}

int main() {
  string txt, pat;
  cin >> pat >> txt;
  ll n, m;
  n = txt.size();
  m = pat.size();
  z_algo(pat + "$" + txt, m);
  return 0;
}