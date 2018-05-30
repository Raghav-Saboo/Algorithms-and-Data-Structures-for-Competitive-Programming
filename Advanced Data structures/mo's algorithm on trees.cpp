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
ll BS=sqrt(N);
ll arr[N];
ll freq[N];
ll P[N][mxlgn];
ll level[N];
ll par[N];
ll vis[N];
ll startn[N],endn[N];
vector <ll> adj[N];
ll occur_node[N];
ll new_arr[4*N];
ll gc;
struct qu
{
    ll l;
    ll r;
    ll id;
    ll ty;
    ll ex;
};
ll ans[100005];
struct qu query[100005];
int cmp(struct qu a,struct qu b)
{
    if(a.l/BS!=b.l/BS)
    {
        return a.l/BS < b.l/BS;
    }
    return a.r<b.r;
}
void pre_lca(ll n)
{
    ll i,j;
    for(j=1;(1<<j)<=n;j++)
    {
        fu(i,1,n)
        {
            P[i][j]=-1;
        }
    }
    fu(i,1,n)
    {
        P[i][0]=par[i];
    }
    for(j=1;(1<<j)<=n;j++)
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
ll lcaquery(ll u,ll v)
{
    if(level[u]<level[v])
    {
        ll tmp=u;
        u=v;
        v=tmp;
    }
    ll log1=0;
    for(log1=1;(1<<log1)<=level[u];log1++);
    log1--;
    ll i;
    for(i=log1;i>=0;i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            u=P[u][i];
        }
    }
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
void dfs(ll u,ll pr,ll lv)
{
    par[u]=pr;
    vis[u]=1;
    level[u]=lv;
    startn[u]=++gc;
    new_arr[gc]=u;
    for(ll v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v,u,lv+1);
        }
    }
    endn[u]=++gc;
    new_arr[gc]=u;
}
void add_rem(ll pos,ll &an)
{
    ll wt=arr[new_arr[pos]];
    //cout<<pos<<" "<<new_arr[pos]<<" "<<wt<<" "<<freq[wt]<<" "<<occur_node[new_arr[pos]]<<" ***"<<endl;
    if(!occur_node[new_arr[pos]])
    {
        freq[wt]++;
        if(freq[wt]==1)
        {
            an++;
        }
    }
    else
    {
        freq[wt]--;
        if(freq[wt]==0)
        {
            an--;
        }
    }
    occur_node[new_arr[pos]]^=1;
}
int main()
{
    ll n,i,q,l,r,u,v;
    sl(n);sl(q);
    map <ll,ll> fm;
    fu(i,1,n)
    {
        sl(arr[i]);
        fm[arr[i]]++;
    }
    i=0;
    for(map<ll,ll> :: iterator it=fm.begin();it!=fm.end();it++)
    {
        fm[it->first]=++i;
    }
    fu(i,1,n)
    {
        arr[i]=fm[arr[i]];
    }
    fu(i,1,n-1)
    {
        sl(u);sl(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,1);
    pre_lca(n);
    //cout<<"Hello\n";
    fu(i,1,q)
    {
        sl(l);sl(r);
        if(startn[l]>startn[r])
        {
            ll tmp=l;
            l=r;
            r=tmp;
        }
        ll lca=lcaquery(l,r);
        //cout<<lca<<endl;
        if(lca==l)
        {
            query[i].l=startn[l];
            query[i].r=startn[r];
            query[i].id=i;
            query[i].ty=1;
        }
        else
        {
            query[i].l=endn[l];
            query[i].r=startn[r];
            query[i].id=i;
            query[i].ty=2;
            query[i].ex=startn[lca];
        }
        //cout<<i<<" %%%%%%% "<<query[i].l<<" "<<query[i].r<<" "<<l<<" "<<r<<endl;
    }
    //cout<<"Hello\n";
    sort(query+1,query+q+1,cmp);
    ll cl,cr;
    cl=1;
    cr=1;
    ll an=0;
    fu(i,1,q)
    {
        l=query[i].l;
        r=query[i].r;
        //cout<<l<<" "<<r<<endl;
        while(cl>query[i].l)
        {
            cl--;
            add_rem(cl,an);
        }
        while(cr<=query[i].r)
        {
            add_rem(cr,an);
            cr++;
        }
        while(cl<query[i].l)
        {
            add_rem(cl,an);
            cl++;
        }
        while(cr-1>query[i].r)
        {
            add_rem(cr-1,an);
            cr--;
        }
        //cout<<an<<" &^&^&"<<" "<<query[i].id<<" "<<query[i].ty<<endl;
        if(query[i].ty==1)
        {
            ans[query[i].id]=an;
        }
        else
        {
            add_rem(query[i].ex,an);
            ans[query[i].id]=an;
            add_rem(query[i].ex,an);
        }
    }
    fu(i,1,q)
    {
        pl(ans[i]);pn();
    }
    return 0;
}