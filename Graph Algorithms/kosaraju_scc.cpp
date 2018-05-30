//Problem link https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/problem-to-be-linked-with-strongly-connected-component-tutorial/
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
vector <ll> adj[N],radj[N];
ll vis[N];
ll ans=0;
void topo_sort(stack <ll> &st,ll u)
{
    ll i;
    vis[u]=1;
    rep(i,adj[u].size())
    {
        if(!vis[adj[u][i]])
        {
            topo_sort(st,adj[u][i]);
        }
    }
    st.push(u);    
}
void dfs(ll u,ll &cnt)
{
    ll i;
    vis[u]=1;
    cnt++;
    rep(i,radj[u].size())
    {
        if(!vis[radj[u][i]])
        {
            dfs(radj[u][i],cnt);
        }
    }
}
void kosaraju(ll n)
{
    ll i,u;
    fu(i,1,n)
    {
        vis[i]=0;
    }
    stack <ll> st;
    fu(i,1,n)
    {
        if(!vis[i])
        {
            topo_sort(st,i);
        }
    }
    fu(i,1,n)
    {
        vis[i]=0;
    }
    while(!st.empty())
    {
        u=st.top();
        st.pop();
        if(vis[u])
        {
            continue;
        }
        ll cnt=0;
        dfs(u,cnt);
        if(cnt%2==0)
        {
            ans-=cnt;
        }
        else
        {
            ans+=cnt;
        }
    }
}
int main()
{
    ll n,m,u,v,i;
    sl(n);
    sl(m);
    fu(i,1,m)
    {
        sl(u);
        sl(v);
        adj[u].pb(v);
        radj[v].pb(u);
    }
    kosaraju(n);
    pl(ans);
    pn();
    return 0;
}