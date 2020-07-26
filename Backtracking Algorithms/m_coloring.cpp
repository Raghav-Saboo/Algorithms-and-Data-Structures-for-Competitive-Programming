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
#define N 25
using namespace std;
ll adj[N][N], color[N];

bool issafe(ll v, ll c, ll n) {
    if (color[v] != 0) {
        return false;
    }
    ll i;
    fu(i, 1, n) {
        if (adj[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

ll m_color(ll n, ll v, ll m) {
    if (v == n + 1) {
        return 1;
    }
    ll i;
    fu(i, 1, m) {
        if (issafe(v, i, n)) {
            color[v] = i;
            if (m_color(n, v + 1, m)) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    ll t, n, m, i, j, e;
    sl(t);
    while (t--) {
        sl(n);
        sl(m);
        sl(e);
        fu(i, 1, n) {
            color[i] = 0;
            fu(j, 1, n) {
                adj[i][j] = 0;
            }
        }
        while (e--) {
            ll u, v;
            sl(u);
            sl(v);
            adj[u][v] = adj[v][u] = 1;
        }
        pl(m_color(n, 1, m));
        pn();
    }
    return 0;
}