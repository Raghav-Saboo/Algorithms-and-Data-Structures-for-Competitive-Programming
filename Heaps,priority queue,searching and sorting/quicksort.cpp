//Problem link https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/bfs/
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

ll partition(ll s, ll e) {
    ll i, pi = s;
    ll pivot = arr[e];
    fu(i, s, e - 1) {
        if (arr[i] <= pivot) {
            ll tmp = arr[i];
            arr[i] = arr[pi];
            arr[pi] = tmp;
            pi++;
        }
    }
    ll tmp = arr[e];
    arr[e] = arr[pi];
    arr[pi] = tmp;
    return pi;
}

ll randomized_partition(ll s, ll e) {
    ll n = e - s + 1;
    ll id = s + rand() % n;
    ll tmp = arr[e];
    arr[e] = arr[id];
    arr[id] = tmp;
    return partition(s, e);
}

void quick_sort(ll s, ll e) {
    if (s < e) {
        ll pi = randomized_partition(s, e);
        quick_sort(s, pi - 1);
        quick_sort(pi + 1, e);
    }
}

int main() {
    srand(time(NULL));
    ll n, i;
    sl(n);
    fu(i, 1, n) {
        sl(arr[i]);
    }
    quick_sort(1, n);
    fu(i, 1, n) {
        pl(arr[i]);
        ps();
    }
    pn();
    return 0;
}