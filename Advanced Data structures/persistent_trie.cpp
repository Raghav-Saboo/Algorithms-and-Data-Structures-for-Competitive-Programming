//Problem Link https://www.codechef.com/problems/GPD
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
#define N 3000005
struct trie
{
    struct trie *c[2];
};
struct trie *root[N];
vector <ll> adj[N];
map <ll,ll> rid;
ll key[N];
trie *create()
{
    trie *r=new trie();
    r->c[0]=r->c[1]=NULL;
    return r;
}
trie *insert(trie *prv,ll k,ll id)
{
    if(id<0)
    {
        return create();
    }
    //cout<<id<<endl;
    ll r=(k>>id)&1;
    trie *node=create();
    node->c[r^1]=(prv!=NULL?prv->c[r^1]:NULL);
    node->c[r]=insert((prv!=NULL?prv->c[r]:NULL),k,id-1);
    return node;
}
void add(ll u,ll v,ll k)
{
    //cout<<u<<" "<<v<<" "<<k<<endl;
    root[u]=insert((v==-1)?NULL:root[v],k,31);
}
void dfs(ll u,ll par)
{
    add(u,(par==-1)?-1:par,key[u]);
    for(ll v:adj[u])
    { 
        dfs(v,u);
    }
}
ll query_max(trie *node,ll k)
{
    ll i,ans=0;
    fd(i,31,0)
    {
        ll r=(k>>i)&1;
        //cout<<i<<" "<<r<<endl;
        if(node->c[r^1]!=NULL)
        {
            ans+=(1<<i);
            node=node->c[r^1];
            //cout<<i<<" "<<r<<" "<<k<<" "<<ans<<endl;
        }
        else if(node->c[r]!=NULL)
        {
            node=node->c[r];
        }
    }
    return ans;
}
ll query_min(trie *node,ll k)
{
    ll i,ans=0;
    fd(i,31,0)
    {
        ll r=(k>>i)&1;
        if(node->c[r]!=NULL)
        {
            node=node->c[r];
        }
        else if(node->c[r^1]!=NULL)
        {
            //cout<<i<<" "<<k<<" "<<r<<endl;
            ans+=(1<<i);
            node=node->c[r^1];
        }
    }
    return ans;
}
int main()
{
    ll n,q,u,v,i,ty,k,r,rk;
    sl(n);sl(q);
    sl(r);
    sl(rk);
    ll cnt=0;
    rep(i,n-1)
    {
        sl(v);
        sl(u);
        sl(k);
        if(rid.find(u)==rid.end())
        {
            rid[u]=++cnt;
        }
        if(rid.find(v)==rid.end())
        {
            rid[v]=++cnt;
        }
        adj[rid[u]].pb(rid[v]);
        key[rid[v]]=k;
    }
    key[rid[r]]=rk;
    dfs(rid[r],-1);
    ll lastans=0;
    while(q--)
    {
        sl(ty);
        ty^=lastans;
        if(ty==0)
        {
            sl(u);sl(v);sl(k);
            u^=lastans;
            v^=lastans;
            k^=lastans;
            //cout<<u<<" "<<v<<" "<<k<<endl;
            if(rid.find(v)==rid.end())
            {
                rid[v]=++cnt;
            }
            key[rid[v]]=k;
            //cout<<rid[v]<<" "<<rid[u]<<" "<<k<<endl;
            add(rid[v],rid[u],k);
            //break;
        }
        else
        {   
            sl(v);sl(k);
            v^=lastans;
            k^=lastans;
            //cout<<v<<" "<<k<<endl;
            v=rid[v];
            ll mn,mx;
            //cout<<v<<" "<<k<<endl;
            mn=query_min(root[v],k);
            mx=query_max(root[v],k);
            lastans=mn^mx;
            pl(mn);ps();pl(mx);pn();
            //break;
        }
    }
    return 0;
}