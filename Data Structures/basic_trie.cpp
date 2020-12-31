// Problem Link
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
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

struct trie {
  trie *c[26];
  ll pq;

  trie() {
    ll i;
    rep(i, 26) { c[i] = NULL; }
    pq = 0;
  }
};

ll arr[N];

trie *insert(trie *root, string s, ll pq) {
  ll i;
  trie *tmp = root;
  ll l = s.size();
  rep(i, l) {
    ll r = s[i] - 'a';
    tmp->pq = max(tmp->pq, pq);
    if (tmp->c[r] == NULL) {
      tmp->c[r] = new trie();
    }
    tmp = tmp->c[r];
  }
  return root;
}

ll query(trie *root, string s) {
  ll i, ans = -1, l = s.size();
  trie *tmp = root;
  rep(i, l) {
    ll r = s[i] - 'a';
    if (tmp->c[r] != NULL) {
      tmp = tmp->c[r];
    } else {
      return ans;
    }
  }
  if (tmp != NULL) {
    ans = tmp->pq;
  }
  return ans;
}

int main() {
  ll n, q;
  string s;
  ll pq;
  trie *root = new trie();
  sl(n);
  sl(q);
  while (n--) {
    cin >> s >> pq;
    root = insert(root, s, pq);
  }
  while (q--) {
    cin >> s;
    pl(query(root, s));
    pn();
  }
  return 0;
}