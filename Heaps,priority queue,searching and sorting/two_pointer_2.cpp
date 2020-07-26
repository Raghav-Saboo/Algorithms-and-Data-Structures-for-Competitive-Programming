//Problem link http://www.spoj.com/problems/ARRAYSUB/
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
#define N 1000005
ll arr[N];
map<ll, ll> cp;

int main() {
    ll n, i, j, ans, k;
    sl(n);
    fu(i, 1, n) {
        sl(arr[i]);
    }
    sl(k);
    fu(i, 1, k) {
        cp[arr[i]]++;
    }
    pl((cp.rbegin())->first);
    ps();
    fu(i, k + 1, n) {
        cp[arr[i]]++;
        if (cp[arr[i - k]] > 1) {
            cp[arr[i - k]]--;
        } else {
            cp.erase(arr[i - k]);
        }
        pl((cp.rbegin())->first);
        ps();
    }
    pn();
    return 0;
}