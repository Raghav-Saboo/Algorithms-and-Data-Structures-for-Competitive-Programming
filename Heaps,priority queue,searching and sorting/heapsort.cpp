// Problem link https://www.hackerearth.com/practice/
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

void max_heapify(ll id, ll n) {
  ll l, r, largest;
  l = 2 * id;
  r = 2 * id + 1;
  if (l <= n && arr[l] > arr[id]) {
    largest = l;
  } else {
    largest = id;
  }
  if (r <= n && arr[r] > arr[largest]) {
    largest = r;
  }
  if (largest != id) {
    ll tmp = arr[largest];
    arr[largest] = arr[id];
    arr[id] = tmp;
    max_heapify(largest, n);
  }
}

void build_heap(ll n) {
  ll i;
  for (i = n / 2; i >= 1; i--) {
    max_heapify(i, n);
  }
}

void heap_sort(ll n) {
  build_heap(n);
  ll i, hs = n;
  fd(i, n, 2) {
    ll tmp = arr[1];
    // cout<<tmp<<" "<<i<<endl;
    arr[1] = arr[hs];
    arr[hs] = tmp;
    hs--;
    max_heapify(1, hs);
  }
}

int main() {
  ll n, i, j, x;
  sl(n);
  fu(i, 1, n) { sl(arr[i]); }
  heap_sort(n);
  fu(i, 1, n) {
    pl(arr[i]);
    ps();
  }
  pn();
  return 0;
}