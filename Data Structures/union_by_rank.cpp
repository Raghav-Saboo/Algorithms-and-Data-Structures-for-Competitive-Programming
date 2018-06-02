//Problem Link https://www.codechef.com/problems/ABROADS
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
#define N 1000005
struct query
{
    char type;
    ll v1;
    ll v2;
};
vector <ll> popu[N];
struct query arr[N];
ll rankdsu[N];
ll par[N];
multiset <ll> se;
ll mark[N];
pll road[N];
ll siz[N];
ll popl[N];
void make(ll n)
{
    ll i;
    fu(i,1,n)
    {
        par[i]=i;
        siz[i]=popu[i][popu[i].size()-1];
        se.insert(siz[i]);
        rankdsu[i]=1;
    }
}
ll fp(ll x)
{
    if(x==par[x])
    {
        return x;
    }
    return par[x]=fp(par[x]);
}
void uni(ll a,ll b)
{
    ll pa,pb;
    pa=fp(a);
    pb=fp(b);
    if(pa!=pb)
    {
        if(rankdsu[pa]>rankdsu[pb])
        {
            ll tmp=pa;
            pa=pb;
            pb=tmp;
        }
        par[pa]=pb;
        //cout<<a<<" "<<b<<" "<<pa<<" "<<pb<<" "<<siz[pa]<<" "<<siz[pb]<<endl;
        se.erase(se.find(siz[pa]));
        se.erase(se.find(siz[pb]));
        siz[pb]+=siz[pa];
        se.insert(siz[pb]);
        if(rankdsu[pa]==rankdsu[pb])
        {
            rankdsu[pb]++;
        }
    }
}
int main()
{
    ll n,m,q,i,u,v;
    sl(n);sl(m);sl(q);
    fu(i,1,n)
    {
        sl(popl[i]);
        popu[i].pb(popl[i]);
    }
    fu(i,1,m)
    {
        sl(road[i].first);sl(road[i].second);
    }
    fu(i,1,q)
    {
        cin>>arr[i].type;
        if(arr[i].type=='D')
        {
            sl(arr[i].v1);
            mark[arr[i].v1]=1;
        }
        else
        {
            sl(arr[i].v1);sl(arr[i].v2);
            popu[arr[i].v1].pb(arr[i].v2);
        }
    }
    make(n);
    fu(i,1,m)
    {
        if(!mark[i])
        {
            uni(road[i].first,road[i].second);
        }
    }
    vector <ll> ans;
    fd(i,q,1)
    {
        //cout<<i<<endl;
        multiset <ll> :: reverse_iterator rit=se.rbegin();
        ans.pb(*rit);
        //cout<<*rit<<endl;
        if(arr[i].type=='D')
        {
            uni(road[arr[i].v1].first,road[arr[i].v1].second);
        }
        else
        {
            se.erase(se.find(siz[fp(arr[i].v1)]));
            siz[fp(arr[i].v1)]-=popu[arr[i].v1][popu[arr[i].v1].size()-1];
            siz[fp(arr[i].v1)]+=popu[arr[i].v1][popu[arr[i].v1].size()-2];
            se.insert(siz[fp(arr[i].v1)]);
            popu[arr[i].v1].pop_back();
        }
    }
    reverse(all(ans));
    rep(i,ans.size())
    {
        pl(ans[i]);pn();
    }
    return 0;
}
