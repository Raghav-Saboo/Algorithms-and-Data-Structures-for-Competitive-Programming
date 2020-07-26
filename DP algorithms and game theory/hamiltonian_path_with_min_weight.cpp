//Problem Link https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/micro-and-graphdpbitmask-tutorial/
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
#define N 12
ll adj[N][N];
ll dp[1 << N][N];

void hamiltonian(ll n) {
    ll i, j, k, ans;
    rep(i, (1 << n)) {
        rep(j, n) {
            dp[i][j] = 1e9;
        }
    }
    rep(i, n) {
        dp[1 << i][i] = 0;
    }
    rep(i, (1 << n)) {
        rep(j, n) {
            if (i & (1 << j)) {
                rep(k, n) {
                    if (k != j && (i & (1 << k)) && adj[k][j] && dp[i ^ (1 << j)][k] != 1e9) {
                        dp[i][j] = min(dp[i][j], adj[k][j] + dp[i ^ (1 << j)][k]);
                        //cout<<i<<" "<<dp[i][j]<<endl;
                    }
                }
            }
        }
    }
    ans = 1e9;
    rep(i, n) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans << endl;
}

int main() {
    ll n, m, u, v, w;
    sl(n);
    sl(m);
    while (m--) {
        sl(u);
        sl(v);
        sl(w);
        u--;
        v--;
        if (adj[u][v] == 0)
            adj[u][v] = adj[v][u] = w;
        else
            adj[u][v] = min(adj[u][v], w);
        adj[v][u] = w;
    }
    hamiltonian(n);
    return 0;
}