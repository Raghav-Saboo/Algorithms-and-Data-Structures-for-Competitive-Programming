//Problem Link http://www.spoj.com/problems/MKTHNUM/
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i, a, n) for(i=a;i<=n;i++)
#define fd(i, a, n) for(i=a;i>=n;i--)
#define rep(i, n)  for(i=0;i<n;i++)
#define si(i)  scanf("%d",&i)
#define ss(s)  scanf("%s",s)
#define sl(i)  scanf("%lld",&i)
#define pi(i)  printf("%d",i)
#define pl(i)  printf("%lld",i);
#define ps()   printf(" ");
#define pn()   printf("\n");
#define all(v)  v.begin(),v.end()
#define vi vector <int>
#define vl vector <ll>
#define N 1000005
vector<ll> seg[4 * N];
ll arr[N];

void merge(ll a, ll b, ll c) {
    ll i, j;
    i = 0;
    j = 0;
    while (i < seg[a].size() && j < seg[b].size()) {
        if (seg[a][i] < seg[b][j]) {
            seg[c].push_back(seg[a][i]);
            i++;
        } else {
            seg[c].push_back(seg[b][j]);
            j++;
        }
    }
    while (i < seg[a].size()) {
        seg[c].push_back(seg[a][i]);
        i++;
    }
    while (j < seg[b].size()) {
        seg[c].push_back(seg[b][j]);
        j++;
    }
}

void build(ll rl, ll rr, ll id) {
    if (rl == rr) {
        seg[id].push_back(arr[rl]);
        return;
    }
    ll mid = (rl + rr) / 2;
    build(rl, mid, 2 * id);
    build(mid + 1, rr, 2 * id + 1);
    merge(2 * id, 2 * id + 1, id);
}

ll query(ll ql, ll qr, ll rl, ll rr, ll id, ll v) {
    if (ql > rr || rl > qr || ql > qr) {
        return 0;
    }
    if (ql <= rl && rr <= qr) {
        return upper_bound(all(seg[id]), v) - seg[id].begin();
    }
    ll mid = (rl + rr) / 2;
    return query(ql, qr, rl, mid, 2 * id, v) + query(ql, qr, mid + 1, rr, 2 * id + 1, v);
}

bool in_range(ll ql, ll qr, ll rl, ll rr, ll id, ll v) {
    if (ql > rr || rl > qr || ql > qr) {
        return false;
    }
    if (ql <= rl && rr <= qr) {
        return binary_search(all(seg[id]), v);
    }
    ll mid = (rl + rr) / 2;
    return in_range(ql, qr, rl, mid, 2 * id, v) || in_range(ql, qr, mid + 1, rr, 2 * id + 1, v);
}

int main() {
    ll n, q, l, r, x, ans, id, i, t, v;
    ll ty;
    map<ll, ll> cp;
    sl(n);
    sl(q);
    fu(i, 1, n) {
        sl(arr[i]);
        cp[arr[i]]++;
    }
    build(1, n, 1);
    while (q--) {
        sl(l);
        sl(r);
        sl(v);
        ll low = -1e9, mid, high = 1e9;
        while (low <= high) {
            mid = (low + high) / 2;
            ll rv = query(l, r, 1, n, 1, mid);
            if (rv == v && in_range(l, r, 1, n, 1, mid)) {
                pl(mid);
                pn();
                break;
            } else if (rv < v) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return 0;
}