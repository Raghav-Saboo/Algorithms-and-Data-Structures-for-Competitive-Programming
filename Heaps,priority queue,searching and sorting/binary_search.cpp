//Problem link https://www.hackerearth.com/practice/
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

int main() {
    ll n, i, x, low, high, mid, ans, q;
    sl(n);
    fu(i, 1, n) {
        sl(arr[i]);
    }
    sort(arr + 1, arr + 1 + n);
    sl(q);
    while (q--) {
        sl(x);
        low = 1;
        high = n;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == x) {
                ans = mid;
                break;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        pl(ans);
        pn();
    }
    return 0;
}