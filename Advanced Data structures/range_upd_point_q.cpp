//Problem Link https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/akash-and-gcd-1-16/
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
ll bit[N];

void upd(ll id, ll v, ll n) {
    while (id <= n) {
        bit[id] += v;
        id += (id & -id);
    }
}

ll query(ll id) {
    ll s = 0;
    while (id > 0) {
        s += bit[id];
        id -= (id & -id);
    }
    return s;
}

int main() {
    ll ty;
    ll t, n, q, l, r, ans, i, v;
    sl(t);
    while (t--) {
        sl(n);
        sl(q);
        while (q--) {
            sl(l);
            sl(r);
            sl(v);
            l++;
            r++;
            upd(l, v, n);
            upd(r + 1, -v, n);
        }
        sl(q);
        while (q--) {
            sl(i);
            i++;
            pl(query(i));
            pn();
        }
        fu(i, 1, n) {
            bit[i] = 0;
        }
    }
    return 0;
}