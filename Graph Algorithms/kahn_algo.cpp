//Problem Link https://practice.geeksforgeeks.org/problems/topological-sort/1
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
vector <ll> adj[N];
ll vis[N];
list <ll> ls;
ll indeg[N];
void topo_sort(ll n)
{
    ll i,u;
    queue <ll> q;
    fu(i,1,n)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        ls.push_back(u);
        cout<<u<<" ";
        rep(i,adj[u].size())
        {
            if(!vis[adj[u][i]])
            {
                indeg[adj[u][i]]--;
                if(indeg[adj[u][i]]==0)
                {
                    vis[adj[u][i]]=1;
                    q.push(adj[u][i]);
                }
            }
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
        indeg[v]++;
    }
    topo_sort(n);
    list <ll> :: iterator it;
    for(it=ls.begin();it!=ls.end();it++)
    {
        pl(*it);
        ps();
    }
    pn();
    return 0;
}