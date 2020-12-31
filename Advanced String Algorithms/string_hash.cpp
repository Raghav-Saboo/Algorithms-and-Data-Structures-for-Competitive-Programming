// Problem link
// https://www.hackerrank.com/contests/inscription2015/challenges/the-natural-selection/problem
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
#define N 2000005
ll B = 1e8 + 7;
ll mod = 1e9 + 9;
ll hash_s[N];
ll pb[N], invb[N];
ll h[N];

void pre_h(string s) {
  ll i, l = s.size();
  h[0] = s[0] - 'a' + 1;
  fu(i, 1, l - 1) {
    h[i] = h[i - 1] + (s[i] - 'a' + 1) * pb[i];
    h[i] %= mod;
  }
}

ll subhash(ll i, ll j) {
  ll ih, jh;
  jh = h[j];
  ih = (i > 0) ? h[i - 1] : 0;
  ll ans = 0;
  ans = (jh - ih + mod) * invb[i];
  ans %= mod;
  return ans;
}

ll get_hash(string s) {
  ll h = 0;
  ll i, l = s.size();
  rep(i, l) {
    h = h + (s[i] - 'a' + 1) * pb[i];
    h %= mod;
  }
  return h;
}

ll mexp(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2 != 0) {
      res *= a;
      res %= mod;
    }
    b /= 2;
    a = (a * a) % mod;
  }
  return res;
}

void pre() {
  ll ib = mexp(B, mod - 2);
  ll i;
  pb[0] = 1;
  invb[0] = 1;
  fu(i, 1, 2 * 1e6) {
    pb[i] = pb[i - 1] * B;
    pb[i] %= mod;
    invb[i] = invb[i - 1] * ib;
    invb[i] %= mod;
  }
}

int main() {
  pre();
  map<ll, ll> hp;
  ll n, q, i;
  string s, s1;
  sl(n);
  while (n--) {
    cin >> s;
    // cout<<s<<" "<<get_hash(s)<<endl;
    hp[get_hash(s)]++;
  }
  sl(q);
  ll ans = 0;
  while (q--) {
    cin >> s1;
    pre_h(s1);
    ll l = s1.size();
    rep(i, l - 1) {
      if (hp.find(subhash(0, i)) != hp.end() &&
          hp.find(subhash(i + 1, l - 1)) != hp.end()) {
        ans++;
        break;
      }
    }
    if (hp.find(get_hash(s1)) != hp.end() && i >= l - 1) {
      ans++;
    }
  }
  pl(ans);
  pn();
  return 0;
}