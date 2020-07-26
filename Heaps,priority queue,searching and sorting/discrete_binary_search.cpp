//Problem link https://codebuddy.co.in/problems/PAINTER
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
#define N 100005
ll arr[N];

ll predicate(ll x, ll n, ll to, ll k) {
    ll i, r = 0, ans = 1;
    fu(i, 1, n) {
        r += arr[i] * to;
        if (r > x) {
            r = arr[i] * to;
            ans++;
        }
    }
    if (ans > k) {
        return 0;
    }
    if (r > x) {
        return 0;
    }
    return 1;
}

ll discrete_bs(ll n, ll k, ll to) {
    ll low = 1, mid, high = 1e15, ans;
    while (low <= high) {
        mid = (low + high) / 2;
        if (predicate(mid, n, to, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ll n, k, to, i, t;
    ll mod = 10000003;
    sl(t);
    while (t--) {
        sl(n);
        sl(k);
        sl(to);
        fu(i, 1, n) {
            sl(arr[i]);
        }
        pl(discrete_bs(n, k, to) % mod);
        pn();
    }
    return 0;
}