//GFG Practice
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
pll arr[N];

int main() {
    ll t, n, i, j, x;
    sl(t);
    while (t--) {
        map<pll, ll> idp;
        sl(n);
        rep(i, n) {
            sl(arr[i].se);
        }
        rep(i, n) {
            sl(arr[i].fi);
            idp[arr[i]] = i + 1;
        }
        sort(arr, arr + n);
        pl(idp[arr[0]]);
        x = arr[0].fi;
        fu(i, 1, n - 1) {
            if (arr[i].se > x) {
                pl(idp[arr[i]]);
                ps();
                x = arr[i].fi;
            }
        }
        pn();
    }
    return 0;
}