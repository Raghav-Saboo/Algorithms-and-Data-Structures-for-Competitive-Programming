//Problem link  http://www.spoj.com/problems/ASSIGN/
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
#define N 21
ll dp[1 << N];
ll arr[N][N];

ll bitmaskdp(ll n) {
    ll i, j, ans = 0, x;
    fu(i, 0, (1 << n) - 1) {
        dp[i] = 0;
    }
    dp[0] = 1;
    fu(i, 0, (1 << n) - 1) {
        ll mask = i;
        x = __builtin_popcount(i);
        fu(j, 1, n) {
            if (!(mask & (1 << (j - 1))) && arr[x + 1][j]) {
                dp[mask | (1 << (j - 1))] += dp[mask];
            }
        }
    }
    ans = dp[(1 << n) - 1];
    return ans;
}

int main() {
    ll t, n, i, j;
    sl(t);
    while (t--) {
        sl(n);
        fu(i, 1, n) {
            fu(j, 1, n) {
                sl(arr[i][j]);
            }
        }
        pl(bitmaskdp(n));
        pn();
    }
    return 0;
}