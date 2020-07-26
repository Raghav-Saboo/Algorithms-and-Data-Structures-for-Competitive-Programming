//GFG Practice
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
#define N 1005
ll coin[N];
ll dp[N][N];
ll cdp[10005];

void min_coins(ll n, ll x) {
    ll i, j, ans;
    ans = -1;
    fu(i, 1, x) {
        cdp[i] = -1;
    }
    fu(i, 1, n) {
        cdp[coin[i]] = 1;
    }
    fu(i, 1, x) {
        if (cdp[i] == -1) {
            ll mn = 1e10;
            fu(j, 1, n) {
                if (i - coin[j] >= 0 && cdp[i - coin[j]] != -1) {
                    mn = min(mn, 1 + cdp[i - coin[j]]);
                }
            }
            if (mn != 1e10) {
                cdp[i] = mn;
            }
        }
    }
    ans = cdp[x];
    pl(ans);
    pn();
}

void no_of_ways(ll n, ll x) {
    ll i, j, ans;
    fu(i, 1, n) {
        fu(j, 1, x) {
            dp[i][j] = 0;
        }
    }
    fu(i, 0, n) {
        dp[i][0] = 1;
    }
    fu(j, 1, x) {
        fu(i, 1, n) {
            dp[i][j] += dp[i - 1][j];
            if (j - coin[i] >= 0) {
                dp[i][j] += dp[i][j - coin[i]];
            }
        }
    }
    pl(dp[n][x]);
    pn();
}

int main() {
    ll t, n, i, x;
    sl(t);
    while (t--) {
        sl(x);
        sl(n);
        fu(i, 1, n) {
            sl(coin[i]);
        }
        //sl(x);
        //no_of_ways(n,x);
        min_coins(n, x);
    }
    return 0;
}