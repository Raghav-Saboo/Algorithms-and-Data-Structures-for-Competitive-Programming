// Codebuddy Practice
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
#define N 10000005
using namespace std;
vector<ll> pr[15];
ll disp[N];
ll arr[N], mx;

void pre() {
  ll i, j;
  fu(i, 2, 1e7) {
    if (!arr[i]) {
      disp[i] = 1;
      for (j = i * 2; j <= 1e7; j += i) {
        disp[j]++;
        arr[j] = 1;
      }
    }
  }
  fu(i, 2, 1e7) {
    pr[disp[i]].pb(i);
    mx = max(mx, disp[i]);
  }
  // cout<<mx<<endl;
}

ll get_ans(ll a, ll b, ll k) {
  if (k > mx) {
    return 0;
  }
  ll ans = upper_bound(all(pr[k]), b) - pr[k].begin();
  ans -= (upper_bound(all(pr[k]), a - 1) - pr[k].begin());
  return ans;
}

int main() {
  pre();
  ll t, a, b, k;
  sl(t);
  while (t--) {
    sl(a);
    sl(b);
    sl(k);
    pl(get_ans(a, b, k));
    pn();
  }
  return 0;
}