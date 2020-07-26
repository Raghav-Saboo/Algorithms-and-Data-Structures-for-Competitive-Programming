// https://www.spoj.com/problems/DISQUERY/
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
#define LGN 20
ll dp[N][LGN][3];
vector <pll> adj[N];
ll vis[N];
ll lev[N], par[N];
ll pared[N];

void dfs(ll u, ll p, ll lv, ll ew) {
    ll i, v, n = adj[u].size(), w;
    vis[u] = 1;
    lev[u] = lv;
    par[u] = p;
    pared[u] = ew;
    rep(i, n) {
        v = adj[u][i].fi;
        w = adj[u][i].se;
        if (!vis[v]) {
            dfs(v, u, lv + 1, w);
        }
    }
}

void precomp(ll n) {
    ll i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; (1 << j) <= n; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = 1e8; // min
            dp[i][j][2] = -1; // max
        }
    }
    for (i = 1; i <= n; i++) {
        dp[i][0][0] = par[i];
        dp[i][0][1] = dp[i][0][2] = pared[i];
    }
    for (j = 1; (1 << j) <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (dp[i][j - 1][0] != -1) {
                dp[i][j][0] = dp[dp[i][j - 1][0]][j - 1][0];
                dp[i][j][1] = min(dp[dp[i][j - 1][0]][j - 1][1], dp[i][j - 1][1]);
                dp[i][j][2] = max(dp[dp[i][j - 1][0]][j - 1][2], dp[i][j - 1][2]);
            }
        }
    }
}

ll lca(ll u, ll v) {
    // cout<<u<<" "<<v<<endl;
    ll tmp, p, q, logi, i;
    p = u;
    q = v;
    if (lev[p] < lev[q]) {
        tmp = p;
        p = q;
        q = tmp;
    }
    for (logi = 1; (1 << logi) <= lev[p]; logi++);
    logi--;
    // cout<<logi<<endl;
    for (i = logi; i >= 0; i--) {
        if (lev[p] - (1 << i) >= lev[q]) {
            p = dp[p][i][0];
        }
    }
    // cout<<p<<endl;
    if (p == q)return p;
    for (i = logi; i >= 0; i--) {
        if (dp[p][i][0] != -1 && dp[p][i][0] != dp[q][i][0]) {
            // cout<<dp[p][i]<<" "<<dp[q][i]<<endl;
            p = dp[p][i][0];
            q = dp[q][i][0];
        }
    }
    return par[p];
}

void cal(ll u, ll lca, ll &mn, ll &mx) {
    ll x = lev[u] - lev[lca], i;
    fd(i, 20, 0) {
        if (x & (1 << i)) {
            mn = min(mn, dp[u][i][1]);
            mx = max(mx, dp[u][i][2]);
            u = dp[u][i][0];
        }
    }
}

int main() {
    ll t, n, q, i, j, x, y, ans, u, v, tc, w, mn, mx;
    sl(n);
    fu(i, 1, n - 1) {
        sl(u);
        sl(v);
        sl(w);
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    dfs(1, -1, 1, -1);
    precomp(n);
    sl(q);
    while (q--) {
        sl(u);
        sl(v);
        ans = lca(u, v);
        mn = 1e8;
        mx = 0;
        cal(u, ans, mn, mx);
        cal(v, ans, mn, mx);
        if (mn == 1e8)mn = 0;
        pl(mn);
        ps();
        pl(mx);
        pn();
    }
    return 0;
}
