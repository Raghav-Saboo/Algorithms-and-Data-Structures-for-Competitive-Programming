// Problem Link http://www.spoj.com/problems/MATSUM/
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
#define N 1025
ll bit[N][N];
ll arr[N][N];

void upd(ll x, ll y, ll v, ll n) {
  while (x <= n) {
    ll y1 = y;
    while (y1 <= n) {
      bit[x][y1] += v;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}

ll query(ll x, ll y) {
  ll s = 0;
  while (x > 0) {
    ll y1 = y;
    while (y1 > 0) {
      s += bit[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
  return s;
}

int main() {
  ll ty;
  ll t, n, q, x1, y1, ans, i, v, x2, y2, j;
  sl(t);
  while (t--) {
    sl(n);
    while (1) {
      char s[10];
      scanf("%s", s);
      // cout<<s<<endl;
      if (strcmp(s, "END") == 0) {
        break;
      } else if (strcmp(s, "SET") == 0) {
        sl(x1);
        sl(y1);
        sl(v);
        x1++;
        y1++;
        upd(x1, y1, v, n);
        upd(x1, y1, -arr[x1][y1], n);
        arr[x1][y1] = v;
      } else {
        ans = 0;
        sl(x1);
        sl(y1);
        sl(x2);
        sl(y2);
        x1++;
        y1++;
        x2++;
        y2++;
        ans += query(x2, y2);
        ans -= query(x1 - 1, y2);
        ans -= query(x2, y1 - 1);
        ans += query(x1 - 1, y1 - 1);
        pl(ans);
        pn();
      }
    }
    fu(i, 1, n) {
      fu(j, 1, n) {
        arr[i][j] = 0;
        bit[i][j] = 0;
      }
    }
  }
  return 0;
}