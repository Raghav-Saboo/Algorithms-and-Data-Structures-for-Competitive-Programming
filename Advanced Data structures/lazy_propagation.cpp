//Problem Link http://www.spoj.com/problems/HORRIBLE/
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
struct node {
    ll val;
};
struct node seg[4 * N];
ll lazy[4 * N];

void build(ll rl, ll rr, ll id) {
    lazy[id] = 0;
    if (rl == rr) {
        seg[id].val = 0;
        return;
    }
    ll mid = (rl + rr) / 2;
    build(rl, mid, 2 * id);
    build(mid + 1, rr, 2 * id + 1);
    seg[id].val = seg[2 * id].val + seg[2 * id + 1].val;
}

ll query(ll ql, ll qr, ll rl, ll rr, ll id) {
    if (ql > rr || rl > qr || ql > qr) {
        return 0;
    }
    if (lazy[id] != 0) {
        seg[id].val += (lazy[id] * (rr - rl + 1));
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
        lazy[id] = 0;
    }
    if (ql <= rl && rr <= qr) {
        return seg[id].val;
    }
    ll mid = (rl + rr) / 2;
    return query(ql, qr, rl, mid, 2 * id) + query(ql, qr, mid + 1, rr, 2 * id + 1);
}

void update(ll ql, ll qr, ll v, ll rl, ll rr, ll id) {
    if (lazy[id] != 0) {
        seg[id].val += (lazy[id] * (rr - rl + 1));
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
        lazy[id] = 0;
    }
    if (ql > rr || rl > qr || ql > qr) {
        return;
    }
    if (ql <= rl && rr <= qr) {
        seg[id].val += v * (rr - rl + 1);
        lazy[2 * id] += v;
        lazy[2 * id + 1] += v;
        lazy[id] = 0;
        return;
    }
    ll mid = (rl + rr) / 2;
    update(ql, qr, v, rl, mid, 2 * id);
    update(ql, qr, v, mid + 1, rr, 2 * id + 1);
    seg[id].val = seg[2 * id].val + seg[2 * id + 1].val;
}

int main() {
    ll n, q, l, r, x, ans, id, i, t, v;
    ll ty;
    sl(t);
    while (t--) {
        sl(n);
        sl(q);
        build(1, n, 1);
        while (q--) {
            sl(ty);
            if (ty == 0) {
                sl(l);
                sl(r);
                sl(v);
                update(l, r, v, 1, n, 1);
            } else {
                sl(l);
                sl(r);
                pl(query(l, r, 1, n, 1));
                pn();
            }
        }
    }
    return 0;
}