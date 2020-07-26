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
#define N 100005
vector<ll> adj[N];
ll vis[N], dis[N];

void bfs(ll src, ll n) {
    ll i, u;
    fu(i, 1, n) {
        vis[i] = 0;
        dis[i] = 1e12;
    }
    dis[src] = 0;
    vis[src] = 1;
    queue<ll> q;
    q.push(src);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        rep(i, adj[u].size()) {
            if (!vis[adj[u][i]]) {
                dis[adj[u][i]] = dis[u] + 1;
                vis[adj[u][i]] = 1;
                q.push(adj[u][i]);
            }
        }
    }
}

int main() {
    ll i, n, m, u, v, x;
    sl(n);
    m = n - 1;
    fu(i, 1, m) {
        sl(u);
        sl(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sl(x);
    ll src = 1;
    bfs(src, n);
    ll ans = 0;
    fu(i, 1, n) {
        if (dis[i] == x - 1) {
            ans++;
        }
    }
    pl(ans);
    pn();
    return 0;
}