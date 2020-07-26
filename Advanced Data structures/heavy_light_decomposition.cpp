//Problem Link http://www.spoj.com/problems/QTREE/
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
#define N 10005
#define mxlgn 30
ll seg[4 * N];
ll chainhead[N], chainind[N], chainsize[N], chainpos[N];
ll posinseg[N];
ll arr[N];
vector <pll> adj[N];
ll tree_size[N];
ll par[N];
ll level[N];
ll P[N][mxlgn];
ll vis[N];
ll chainno, pos;
ll edgin[N][2];

void build(ll rl, ll rr, ll id) {
    if (rl == rr) {
        seg[id] = arr[rl];
        return;
    }
    ll mid = (rl + rr) / 2;
    build(rl, mid, 2 * id);
    build(mid + 1, rr, 2 * id + 1);
    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}

void update(ll indu, ll val, ll rl, ll rr, ll id) {
    if (rl <= indu && indu <= rr) {
        if (rl == rr) {
            seg[id] = val;
            return;
        }
        ll mid = (rl + rr) / 2;
        update(indu, val, rl, mid, 2 * id);
        update(indu, val, mid + 1, rr, 2 * id + 1);
        seg[id] = max(seg[2 * id], seg[2 * id + 1]);
    }
}

ll query(ll ql, ll qr, ll rl, ll rr, ll id) {
    if (ql > rr || rl > qr || ql > qr) {
        return -1;
    }
    if (ql <= rl && rr <= qr) {
        return seg[id];
    }
    ll mid = (rl + rr) / 2;
    return max(query(ql, qr, rl, mid, 2 * id), query(ql, qr, mid + 1, rr, 2 * id + 1));
}

void pre_lca(ll n) {
    ll i, j;
    for (j = 1; (1 << j) < n; j++) {
        fu(i, 1, n) {
            P[i][j] = -1;
        }
    }
    fu(i, 1, n) {
        P[i][0] = par[i];
    }
    for (j = 1; (1 << j) < n; j++) {
        fu(i, 1, n) {
            if (P[i][j - 1] != -1) {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
}

ll lcaquery(ll u, ll v) {
    if (level[u] < level[v]) {
        ll tmp = u;
        u = v;
        v = tmp;
    }
    ll log1 = 0;
    for (log1 = 1; (1 << log1) <= level[u]; log1++);
    log1--;
    ll i;
    for (i = log1; i >= 0; i--) {
        if (level[u] - (1 << i) >= level[v]) {
            u = P[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (i = log1; i >= 0; i--) {
        if (P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return par[u];
}

void dfs(ll u, ll pr, ll lv) {
    par[u] = pr;
    vis[u] = 1;
    level[u] = lv;
    tree_size[u] = 1;
    for (pll pl:adj[u]) {
        ll v = pl.first;
        if (!vis[v]) {
            dfs(v, u, lv + 1);
            tree_size[u] += tree_size[v];
        }
    }
}

void hld(ll cur, ll pared) {
    vis[cur] = 1;
    if (chainhead[chainno] == -1) {
        chainhead[chainno] = cur;
    }
    //cout<<"hello\n";
    chainsize[chainno]++;
    chainind[cur] = chainno;
    chainpos[cur] = chainsize[chainno];
    ll i, mai = -1, ind = -1;
    //cout<<"hello "<<cur<<" "<<adj[cur].size()<<"\n";
    for (i = 0; i < adj[cur].size(); i++) {
        ll v = adj[cur][i].first;
        if (tree_size[v] > mai && !vis[v]) {
            mai = tree_size[v];
            ind = i;
        }
    }
    //cout<<"hello\n";
    if (pared == -1) {
        arr[++pos] = -1;
        posinseg[cur] = pos;
    } else {
        arr[++pos] = pared;
        posinseg[cur] = pos;
    }
    //cout<<"hello\n";
    if (ind >= 0 && !vis[adj[cur][ind].first]) {
        hld(adj[cur][ind].first, adj[cur][ind].second);
    }
    for (i = 0; i < adj[cur].size(); i++) {
        if (i != ind && !vis[adj[cur][i].first]) {
            chainno++;
            ll v = adj[cur][i].first;
            hld(v, adj[cur][i].second);
        }
    }
}

ll query_up(ll u, ll v) {
    ll cur, uchain, vhcain, ans = -1;
    vhcain = chainind[v];
    //cout<<u<<" "<<chainind[u]<<" "<<v<<" "<<chainind[v]<<endl;
    while (1) {
        uchain = chainind[u];
        if (uchain == vhcain) {
            cur = query(posinseg[v] + 1, posinseg[u], 1, pos, 1);
            if (cur > ans) {
                ans = cur;
            }
            break;
        }
        cur = query(posinseg[chainhead[chainind[u]]], posinseg[u], 1, pos, 1);
        if (cur > ans) {
            ans = cur;
        }
        u = chainhead[chainind[u]];
        u = par[u];
    }
    return ans;
}

ll query_hld(ll u, ll v) {
    //cout<<"hello\n";
    ll lca = lcaquery(u, v);
    //cout<<"hello\n";
    //cout<<u<<" "<<v<<" "<<lca<<endl;
    ll ans = max(query_up(u, lca), query_up(v, lca));
    return ans;
}

void upd_hld(ll id, ll val) {
    update(id, val, 1, pos, 1);
}

int main() {
    ll t, n, q, i, ti, a, b, c;
    char s[20];
    sl(t);
    while (t--) {
        sl(n);
        pos = 0;
        fu(i, 1, n) {
            adj[i].clear();
            vis[i] = 0;
            par[i] = -1;
            chainhead[i] = -1;
            chainind[i] = -1;
            chainsize[i] = 0;
            tree_size[i] = 0;
            level[i] = 0;
        }
        fu(i, 1, n - 1) {
            sl(a);
            sl(b);
            sl(c);
            edgin[i][0] = a;
            edgin[i][1] = b;
            adj[a].push_back(mp(b, c));
            adj[b].push_back(mp(a, c));
        }
        dfs(1, -1, 1);
        pre_lca(n);
        //cout<<"hello\n";
        chainno = 1;
        fu(i, 1, n) {
            vis[i] = 0;
        }
        hld(1, -1);
        //cout<<"hello\n";
        build(1, pos, 1);
        while (1) {
            scanf("%s", s);
            if (strcmp(s, "DONE") == 0) {
                break;
            } else if (strcmp(s, "CHANGE") == 0) {
                sl(i);
                sl(ti);
                a = edgin[i][0];
                b = edgin[i][1];
                ll indu = (par[a] == b ? posinseg[a] : posinseg[b]);
                upd_hld(indu, ti);
            } else {
                sl(a);
                sl(b);
                pl(query_hld(a, b));
                pn();
            }
        }
    }
    return 0;
}