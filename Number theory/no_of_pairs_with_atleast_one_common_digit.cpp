//Problem Link http://www.spoj.com/problems/IITKWPCH/
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
ll arr[N], freq[N];

int main() {
    ll t, i, j, ans, x, n;
    sl(t);
    while (t--) {
        sl(n);
        fu(i, 1, n) {
            sl(arr[i]);
            x = arr[i];
            ll mask = 0;
            while (x > 0) {
                mask |= (1 << (x % 10));
                x /= 10;
            }
            freq[mask]++;
        }
        ans = 0;
        rep(i, 1024) {
            ans += freq[i] * (freq[i] - 1) / 2;
            fu(j, i + 1, 1023) {
                if (i & j) {
                    ans += freq[i] * freq[j];
                }
            }
        }
        rep(i, 1024) {
            freq[i] = 0;
        }
        pl(ans);
        pn();
    }
    return 0;
}