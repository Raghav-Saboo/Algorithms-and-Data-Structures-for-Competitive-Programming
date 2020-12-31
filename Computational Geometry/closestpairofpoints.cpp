// Problem link http://www.spoj.com/problems/CLOPPAIR/
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
#define N 50005
struct point {
  ll x;
  ll y;
};
point arr[N];

struct cmppoint {
  bool operator()(const point &a, const point &b) const {
    if (a.x != b.x) {
      return a.x < b.x;
    } else {
      return a.y < b.y;
    }
  }
};

map<point, ll, cmppoint> pi;

int cmpx(point a, point b) { return a.x < b.x; }

int cmpy(point a, point b) { return a.y < b.y; }

double distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

pair<pll, double> brute_force(point px[], point py[], ll n) {
  ll i, j;
  /*fu(i,1,n)
  {
      pl(px[i].x);
      ps();
      printf(" %% ");
      pl(px[i].y);
      pn();
  }*/
  pair<pll, double> ans;
  ans.second = 1e30;
  fu(i, 1, n - 1) {
    fu(j, i + 1, n) {
      if (ans.second > distance(px[i], px[j])) {
        ans.second = distance(px[i], px[j]);
        ans.first.first = pi[px[i]];
        ans.first.second = pi[px[j]];
        // cout<<"$$$$$ "<<px[i].x<<" "<<px[i].y<<" "<<px[j].x<<" "<<px[j].y<<"
        // "<<ans.first.first<<" "<<ans.first.second<<endl;
      }
    }
  }
  return ans;
}

pair<pll, double> in_strip(point strip[], ll n, double min_d) {
  // sort(strip+1,strip+1+n,cmpy);
  ll i, j;
  pair<pll, double> ans;
  ans.second = 1e30;
  fu(i, 1, n - 1) {
    fu(j, i + 1, n) {
      if (strip[j].y - strip[i].y < min_d &&
          ans.second > distance(strip[i], strip[j])) {
        ans.second = distance(strip[i], strip[j]);
        ans.first.first = pi[strip[i]];
        ans.first.second = pi[strip[j]];
        // cout<<ans.first.first<<" "<<ans.first.second<<endl;
      }
    }
  }
  return ans;
}

pair<pll, double> closest_pair(point px[], point py[], ll n) {
  if (n <= 3) {
    return brute_force(px, py, n);
  }
  ll mid = n / 2;
  pair<pll, double> l, r, s;
  ll i, j;
  point pyl[mid + 1], pyr[n - mid + 1];
  ll il = 0, ir = 0;
  fu(i, 1, n) {
    if (py[i].x <= px[mid].x) {
      pyl[++il] = py[i];
    } else {
      pyr[++ir] = py[i];
    }
  }
  l = closest_pair(px, pyl, mid);
  r = closest_pair(px + mid, pyr, n - mid);
  double min_d = min(l.second, r.second);
  ll ss = 0;
  fu(i, 1, n) {
    if (abs(px[i].x - px[mid].x) <= min_d) {
      ss++;
    }
  }
  point strip[ss + 1];
  ss = 0;
  fu(i, 1, n) {
    if (abs(py[i].x - px[mid].x) < min_d) {
      // cout<<py[i].x<<" "<<px[mid].x<<" &&&&\n";
      strip[++ss] = py[i];
    }
  }
  /*cout<<min_d<<" ()()()\n";
  fu(i,1,ss)
  {
      cout<<strip[i].x<<" ### "<<strip[i].y<<endl;
  }*/
  s = in_strip(strip, ss, min_d);
  if (l.second < r.second && l.second < s.second) {
    return l;
  } else if (r.second < l.second && r.second < s.second) {
    return r;
  } else {
    return s;
  }
}

int main() {
  ll n, i;
  sl(n);
  point px[N], py[N];
  fu(i, 1, n) {
    sl(arr[i].x);
    sl(arr[i].y);
    px[i] = arr[i];
    py[i] = arr[i];
    pi[arr[i]] = i;
  }
  fu(i, 1, n) {
    // cout<<arr[i].x<<" "<<arr[i].y<<" "<<pi[arr[i]]<<endl;
  }
  sort(px + 1, px + 1 + n, cmpx);
  sort(py + 1, py + 1 + n, cmpy);
  pair<pll, double> ans = closest_pair(px, py, n);
  if (ans.first.first > ans.first.second) {
    ll tmp = ans.first.first;
    ans.first.first = ans.first.second;
    ans.first.second = tmp;
  }
  pl(ans.first.first - 1);
  ps();
  pl(ans.first.second - 1);
  ps();
  printf("%.6lf\n", ans.second);
  return 0;
}