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
#define N 4005
ll dp[N];
ll len[N];
ll val[N];
ll s[N];

void rod_cut(ll n, ll x) {
    ll i, j;
    ll ans = 0;
    fu(i, 1, x) {
        dp[i] = 0;
        s[i] = 0;
    }
    fu(i, 1, x) {
        fu(j, 1, n) {
            if (i - len[j] >= 0) {
                if (dp[i] < val[j] + dp[i - len[j]]) {
                    s[i] = len[j];
                }
                dp[i] = max(dp[i], val[j] + dp[i - len[j]]);
            }
        }
    }
    ans = dp[x];
    pl(ans);
    pn();
    while (x > 0 && s[x] > 0) {
        cout << s[x] << " ";
        x = x - s[x];
    }
}

int main() {
    ll t, n, x, i;
    sl(t);
    while (t--) {
        sl(x);
        sl(n);
        fu(i, 1, n) {
            sl(len[i]);
        }
        fu(i, 1, n) {
            sl(val[i]);
        }
        rod_cut(n, x);
    }
    return 0;
}