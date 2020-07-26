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
#define N 105
ll arr[N], b[N], freq[N];
ll c[N];

void counting_sort(ll n, ll k) {
    ll i;
    fu(i, 1, n) {
        c[arr[i]]++;
    }
    fu(i, 1, k) {
        freq[i] = c[i];
    }
    fu(i, 1, k) {
        c[i] += c[i - 1];
    }
    fd(i, n, 1) {
        b[c[arr[i]]] = arr[i];
        c[arr[i]]--;
    }
}

int main() {
    ll n, i, j, x, k = 0;
    sl(n);
    fu(i, 1, n) {
        sl(arr[i]);
        k = max(k, arr[i]);
    }
    counting_sort(n, k);
    fu(i, 1, k) {
        if (freq[i] > 0) {
            pl(i);
            ps();
            pl(freq[i]);
            pn();
        }
    }
    return 0;
}