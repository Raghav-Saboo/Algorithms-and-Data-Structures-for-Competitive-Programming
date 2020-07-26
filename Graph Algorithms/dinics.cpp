//Problem Link http://www.spoj.com/problems/MTOTALF/
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,double>
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
#define N 1005
vector<ll> adj[N], residual[N], level_graph[N];
ll flow[N][N], cf[N][N];
ll c[N][N];
ll dis[N];
ll vis[N];
set <pll> edge;

void assign_levels_residual_bfs(ll src, ll sink, ll n) {
    ll i;
    fu(i, 1, n) {
        dis[i] = 1e12;
        vis[i] = 0;
    }
    queue<ll> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v:residual[u]) {
            if (!vis[v]) {
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
        vis[u] = 2;
    }
}

ll find_path_level_graph(ll src, ll sink, ll n) {
    ll i;
    fu(i, 1, n) {
        vis[i] = 0;
    }
    queue<ll> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v:level_graph[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
        vis[u] = 2;
    }
    return vis[sink];
}

ll get_flow_in_level_graph(ll src, ll sink, ll u, ll start[], ll tflow) {
    if (u == sink) {
        return tflow;
    }
    for (; start[u] < level_graph[u].size(); start[u]++) {
        ll v = level_graph[u][start[u]];
        if (c[u][v] - flow[u][v] > 0) {
            ll cflow = min(tflow, c[u][v] - flow[u][v]);
            ll gflow = get_flow_in_level_graph(src, sink, v, start, cflow);
            //cout<<u<<" "<<v<<" "<<c[u][v]<<" "<<flow[u][v]<<" "<<cflow<<" "<<gflow<<endl;
            if (gflow > 0) {
                flow[u][v] += gflow;
                return gflow;
            }
        }
    }
    return 0;
}

ll dinics(ll src, ll sink, ll n) {
    ll i, j, ans = 0;
    while (1) {
        fu(i, 1, n) {
            fu(j, 1, n) {
                cf[i][j] = 0;
            }
        }
        fu(i, 1, n) {
            for (ll v:adj[i]) {
                cf[i][v] = c[i][v] - flow[i][v];
                cf[v][i] = flow[i][v];
            }
        }
        fu(i, 1, n) {
            fu(j, 1, n) {
                if (cf[i][j] > 0) {
                    residual[i].pb(j);
                }
            }
        }
        assign_levels_residual_bfs(src, sink, n);
        fu(i, 1, n) {
            fu(j, 1, n) {
                if (dis[j] == dis[i] + 1 && cf[i][j] > 0) {
                    level_graph[i].pb(j);
                }
            }
        }
        if (find_path_level_graph(src, sink, n) == 0) {
            break;
        }
        ll *start = new ll[n + 1];
        memset(start, 0, sizeof(ll) * (n + 1));
        while (ll tflow = get_flow_in_level_graph(src, sink, src, start, 1e10)) {
            ans += tflow;
            //cout<<tflow<<endl;
        }
        fu(i, 1, n) {
            residual[i].clear();
            level_graph[i].clear();
        }
    }
    return ans;
}

int main() {
    ll n, m, u, v, i, w;
    string a, b;
    sl(n);
    //sl(m);
    map<string, int> si;
    i = 0;
    map<pair<string, string>, ll> ssl;
    while (cin >> a) {
        cin >> b >> w;
        ssl[mp(a, b)] += w;
        /*if(ssl.find(mp(a,b))!=ssl.end()&&ssl[mp(a,b)]<w)
        {
            ssl[mp(a,b)]=w;
        }
        else if(ssl.find(mp(a,b))==ssl.end())
        {
            ssl[mp(a,b)]=w;
        }*/
    }
    for (map < pair < string, string >, ll > ::iterator it = ssl.begin(); it != ssl.end();
    it++)
    {
        a = it->first.first;
        b = it->first.second;
        w = it->second;
        if (si.find(a) == si.end()) {
            si[a] = ++i;
        }
        if (si.find(b) == si.end()) {
            si[b] = ++i;
        }
        u = si[a];
        v = si[b];
        //cout<<a<<" "<<u<<" "<<v<<" "<<b<<endl;
        adj[u].pb(v);
        edge.insert(mp(u, v));
        c[u][v] = w;
    }
    ll src = si["A"];
    ll sink = si["Z"];
    pl(dinics(src, sink, n));
    pn();
    return 0;
}