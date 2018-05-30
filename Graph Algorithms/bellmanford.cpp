//Problem Link http://www.spoj.com/problems/ARBITRAG/
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
vector < pair <ll,double> > adj[N];
double d[N];
void bellman_ford(ll src,ll n,ll &ans)
{
    ll i,j;
    fu(i,1,n)
    {
        d[i]=1e12;
    }
    d[src]=0;
    rep(i,n-1)
    {
        fu(j,1,n)
        {
            for(pair <ll,double> u:adj[j])
            {
                if(d[u.first]>d[j]+u.second)
                {
                    d[u.first]=d[j]+u.second;
                }
            }
        }
    }
    fu(j,1,n)
    {
        for(pair <ll,double> u:adj[j])
        {
            if(d[u.first]>d[j]+u.second)
            {
                ans=1;
                return;
            }
        }
    }
    ans=0;
    return;
}
int main()
{
    ll n,m,u,v,i,t,w,tn=1;
    map <string,int> sp;
    while(1)
    {
        sl(n);
        string s,s1;
        fu(i,1,n)
        {
            cin>>s;
            sp[s]=i;
        }
        if(n==0)
        {
            break;
        }
        sl(m);
        fu(i,1,m)
        {
            cin>>s;
            double w;
            cin>>w;
            cin>>s1;
            u=sp[s];
            v=sp[s1];
            w=-1.0*log(w);
            adj[u].pb(mp(v,w));
        }
        ll ans=0;
        bellman_ford(1,n,ans);
        if(ans==1)
        {
            printf("Case %lld: Yes\n",tn);
        }
        else
        {
            printf("Case %lld: No\n",tn);
        }
        fu(i,1,n)
        {
            adj[i].clear();
        }
        tn++;
        sp.clear();
    }
    return 0;
}