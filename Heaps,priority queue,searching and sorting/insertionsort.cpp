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
#define N 105
ll arr[N], b[N];
ll ind[N];

int main() {
    ll n, i, j, hole, ans = 0;
    sl(n);
    fu(i, 1, n) {
        sl(arr[i]);
        b[i] = arr[i];
    }
    fu(i, 1, n) {
        ll value = arr[i];
        hole = i;
        while (hole > 1 && arr[hole - 1] > value) {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
    fu(i, 1, n) {
        ind[arr[i]] = i;
    }
    fu(i, 1, n) {
        pl(ind[b[i]]);
        ps();
    }
    pn();
    return 0;
}