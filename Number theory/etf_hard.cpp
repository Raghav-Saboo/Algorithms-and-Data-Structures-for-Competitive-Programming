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
#define N 1000005
using namespace std;
ll phi[N];
ll ans[N];

void pre() {
  ll i, j;
  fu(i, 1, 1e6) { phi[i] = i; }
  fu(i, 1, 1e6) {
    for (j = 2 * i; j <= 1e6; j += i) {
      phi[j] -= phi[i];
    }
  }
  fu(i, 1, 1e6) { ans[i] = ans[i - 1] + phi[i] * phi[i]; }
}

int main() {
  pre();
  ll t, a, b, an;
  sl(t);
  ll tc = 1;
  while (t--) {
    sl(a);
    sl(b);
    an = ans[b] - ans[a - 1];
    printf("Case %lld: %lld\n", tc, an);
    tc++;
  }
  return 0;
}