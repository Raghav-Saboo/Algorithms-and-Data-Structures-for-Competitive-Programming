// GFG Practice
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
#define N 1005
ll arr[N];

void kadane(ll n) {
  ll i, msf, meh, j = -1005;
  fu(i, 1, n) {
    j = max(j, arr[i]);
    if (arr[i] > 0) {
      break;
    }
  }
  if (i > n) {
    cout << j << endl;
    return;
  }
  msf = 0;
  meh = 0;
  fu(i, 1, n) {
    meh = meh + arr[i];
    if (meh < 0) {
      meh = 0;
    }
    if (msf < meh) {
      msf = meh;
      j = i;
    }
  }
  cout << msf << endl;
  return;
  ll tmp = 0;
  fd(i, j, 1) {
    tmp += arr[i];
    if (tmp == msf) {
      break;
    }
  }
  if (i >= 1) {
    ll k;
    fu(k, i, j) { cout << arr[k] << " "; }
    cout << endl;
  }
}

int main() {
  ll t, n, i;
  sl(t);
  while (t--) {
    sl(n);
    fu(i, 1, n) { sl(arr[i]); }
    kadane(n);
  }
  return 0;
}