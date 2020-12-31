// Problem link
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/bfs/
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
#define N 105
ll arr[N];

int main() {
  ll n, i, j, x, ans = 0;
  sl(n);
  sl(x);
  fu(i, 1, n) { sl(arr[i]); }
  fu(i, 1, x) {
    ll imin = i;
    fu(j, i + 1, n) {
      if (arr[j] < arr[imin]) {
        imin = j;
      }
    }
    ll tmp = arr[imin];
    arr[imin] = arr[i];
    arr[i] = tmp;
  }
  fu(i, 1, n) {
    pl(arr[i]);
    ps();
  }
  pn();
  return 0;
}