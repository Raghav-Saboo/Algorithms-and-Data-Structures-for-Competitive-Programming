//Problem Link http://www.spoj.com/problems/KPRIMESB/
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
ll arr[N], np[N];

void pre() {
    ll i, j;
    fu(i, 2, 1e6) {
        if (!arr[i]) {
            for (j = i * i; j <= 1e6; j += i) {
                arr[j] = 1;
            }
        }
    }
    fu(i, 2, 1e6) {
        np[i] = np[i - 1] + !arr[i];
    }
}

int main() {
    pre();
    ll n, k, t, i, j, ans, tc = 1;
    sl(t);
    while (t--) {
        vector<ll> pr;
        sl(n);
        sl(k);
        rep(i, k) {
            sl(j);
            pr.pb(j);
        }
        ans = 0;
        if (n == 0) {
            ans = 0;
        } else {
            for (i = 1; i < (1 << k); i++) {
                ll x = 1, c = 0;
                for (j = 0; j < k; j++) {
                    if (i & (1 << j)) {
                        c++;
                        x *= pr[j];
                    }
                }
                ans = ans + (c % 2 != 0 ? n / x : -n / x);
            }
            //cout<<ans<<" "<<np[n]<<endl;
            if (ans == 0) {
                ans = n - np[n] - 1;
            } else {
                ans = n - np[n] - (ans - k) - 1;
            }
        }
        printf("Case %lld: %lld", tc, ans);
        pn();
        tc++;
    }
    return 0;
}