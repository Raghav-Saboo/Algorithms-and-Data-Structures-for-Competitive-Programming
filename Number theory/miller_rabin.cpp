//Problem Link http://www.spoj.com/problems/PON/
#include <bits/stdc++.h>

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
using namespace std;
ll arr[N];

void pre() {
    ll i, j;
    fu(i, 2, 1e6) {
        if (!arr[i]) {
            for (j = i * i; j <= 1e6; j += i) {
                arr[j] = 1;
            }
        }
    }
    arr[1] = arr[0] = 1;
}

ll mulmod(ll a, ll b, ll m) {
    ll res = 0;
    while (b > 0) {
        if (b % 2 != 0) {
            res += a;
            res %= m;
        }
        a = (a + a) % m;
        b /= 2;
    }
    return res;
}

ll modulo(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mulmod(res, a, m);
        }
        a = mulmod(a, a, m);
        b /= 2;
    }
    return res;
}

bool Miller_rabin(ll p, ll iterations) {
    if (p <= 1e6) {
        return !arr[p];
    }
    if (p % 2 == 0 && p != 2) {
        return false;
    }
    ll i, tmp, s = p - 1;
    while (s % 2 == 0) {
        s /= 2;
    }
    rep(i, iterations) {
        ll a = rand() % (p - 1) + 1;
        ll tmp = s;
        ll mod = modulo(a, tmp, p);
        while (mod != p - 1 && mod != 1 && tmp != p - 1) {
            mod = mulmod(mod, mod, p);
            tmp *= 2;
        }
        if (mod != p - 1 && tmp % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    pre();
    ll t, n;
    sl(t);
    while (t--) {
        sl(n);
        if (Miller_rabin(n, 25)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}