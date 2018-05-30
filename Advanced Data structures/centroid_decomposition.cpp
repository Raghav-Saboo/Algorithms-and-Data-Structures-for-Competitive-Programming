//Problem Link http://www.spoj.com/problems/QTREE5/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,a,n) for(i=a;i>=n;i--)
#define rep(i,n)  for(i=0;i<n;i++)
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
#define mxlgn 30
ll P[N][mxlgn];
ll vis[N];
ll level[N];
ll par[N];
multiset <ll> mn[N];
ll parc[N];
ll ans[N];
vector <ll> adj[N];
vector <ll> cen[N];
ll col[N];
ll tree_size[N];
void pre_lca(ll n)
{
    ll i,j;
    for(j=1;(1<<j)<n;j++)
    {
        fu(i,1,n)
        {
            P[i][j]=-1;
        }
    }
    fu(i,1,n)
    {
        P[i][0]=par[i];
        //cout<<i<<" "<<par[i]<<" @@@"<<endl;
    }
    for(j=1;(1<<j)<n;j++)
    {
        fu(i,1,n)
        {
            if(P[i][j-1]!=-1)
            {
                P[i][j]=P[P[i][j-1]][j-1];
            }
        }
    }
}
ll lca_query(ll u,ll v)
{
    ll i,tmp,log1;
    if(level[u]<level[v])
    {
        tmp=u;u=v;v=tmp;
    }
    log1=0;
    for(log1=1;(1<<log1)<=level[u];log1++);
    log1--;
    //cout<<u<<" "<<v<<" "<<log1<<" ()()"<<endl;
    for(i=log1;i>=0;i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            //cout<<i<<" "<<u<<" "<<P[u][i]<<" "<<par[u]<<" ()()()()\n";
            u=P[u][i];
        }
    }
    //cout<<u<<" "<<v<<" ()()"<<endl;
    if(u==v)
    {
        return u;
    }
    for(i=log1;i>=0;i--)
    {
        if(P[u][i]!=-1&&P[u][i]!=P[v][i])
        {
            u=P[u][i];v=P[v][i];
        }
    }
    return par[u];
}
void dfs(ll u,ll pr,ll lev)
{
    vis[u]=1;
    par[u]=pr;
    level[u]=lev;
    tree_size[u]=1;
    for(ll v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v,u,lev+1);
            tree_size[u]+=tree_size[v];
        }
    }
}
void dfsc(ll u,ll &c,ll n)
{
    ll flag=0;
    for(ll v:adj[u])
    {
        if(tree_size[v]>n/2)
        {
            flag=1;
            ll ptsu,ptsv;
            ptsu=tree_size[u];
            ptsv=tree_size[v];
            tree_size[u]=n-tree_size[v];
            tree_size[v]=n;
            dfsc(v,c,tree_size[v]);
            if(!c)
            {
                tree_size[u]=ptsu;
                tree_size[v]=ptsv;
            }
        }
    }
    if(!flag)
    {
        c=u;
    }
}
ll centroid(ll u,ll n)
{
    ll c=0;
    dfsc(u,c,n);
    if(tree_size[c]<=1)
    {
        return c;
    }
    ll sc=tree_size[c];
    tree_size[c]=0;
    for(ll v:adj[c])
    {
        if(tree_size[v]>=1)
        {
            ll tmp=centroid(v,tree_size[v]);
            cen[c].pb(tmp);
            parc[tmp]=c;
            //cout<<" ^^^^ "<<tmp<<" "<<c<<endl;        
        }
    }
    tree_size[c]=sc;
    return c;
}
ll distance(ll u,ll v)
{
    //cout<<"*** "<<u<<" "<<v<<endl;
    ll lca=lca_query(u,v);
    //cout<<" lca is "<<lca<<endl;
    return level[u]+level[v]-2*level[lca];
}
int main()
{
    ll n,u,v,i,q,ty;
    sl(n);
    fu(i,1,n-1)
    {
        sl(u);
        sl(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,1);
    pre_lca(n);
    fu(i,1,n)
    {
        vis[i]=0;
        col[i]=0;
        ans[i]=1e10;
        mn[i].insert(ans[i]);
    }
    centroid(1,n);
    sl(q);
    while(q--)
    {
        sl(ty);
        sl(u);
        if(ty==0)
        {
            col[u]=1-col[u];
            if(col[u]==0)
            {
                i=u;
                while(i!=0)
                {
                    mn[i].erase(mn[i].find(distance(i,u)));
                    ans[i]=*(mn[i].begin());
                    i=parc[i];
                }
            }
            else
            {
                i=u;
                while(i!=0)
                {
                    ans[i]=min(ans[i],distance(i,u));
                    //cout<<i<<" "<<ans[i]<<" ***"<<endl;
                    mn[i].insert(distance(i,u));
                    i=parc[i];
                    //cout<<i<<endl;
                }
            }
        }
        else
        {
            i=u;
            ll fans=1e10;
            while(i!=0)
            {
                fans=min(fans,distance(i,u)+ans[i]);
                //cout<<u<<" "<<i<<" "<<distance(i,u)+ans[i]<<endl;
                i=parc[i];
            }
            if(fans==1e10)
            {
                fans=-1;
            }
            pl(fans);pn();
        }
    }
    return 0;
}