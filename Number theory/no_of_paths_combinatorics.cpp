//Problem Link http://www.spoj.com/problems/UCV2013E/
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
#define N 505
using namespace std;
ll x[N], y[N];
ll fac[N], ifac[N];
ll mod = 1e9 + 7;

ll mexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res *= a;
            res %= m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

void pre() {
    ll i;
    fac[0] = ifac[0] = 1;
    fu(i, 1, 500) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        ifac[i] = ifac[i - 1] * mexp(i, mod - 2, mod);
        ifac[i] %= mod;
    }
}

int main() {
    pre();
    ll t, i, j, ans, n;
    //sl(t);
    while (1) {
        sl(n);
        if (n == 0)break;
        fu(i, 1, n) {
            sl(x[i]);
        }
        fu(i, 1, n) {
            sl(y[i]);
        }
        ans = 0;
        fu(i, 1, n) {
            ans += abs(x[i] - y[i]);
        }
        ans = fac[ans];
        fu(i, 1, n) {
            ans *= ifac[abs(x[i] - y[i])];
            ans %= mod;
        }
        pl(ans);
        pn();
    }
    return 0;
}