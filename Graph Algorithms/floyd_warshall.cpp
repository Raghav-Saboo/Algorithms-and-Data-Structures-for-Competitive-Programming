//Problem Link http://www.spoj.com/problems/CHICAGO/
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
#define N 1005
vector <pld> adj[N];
double d[N][N];
void floyd_warshall(ll n)
{
    ll i,j,k;
    fu(i,1,n)
    {
        fu(j,1,n)
        {
            d[i][j]=-1.0;
        }
        d[i][i]=1.0;
    }
    fu(i,1,n)
    {
        for(pld u:adj[i])
        {
            d[i][u.first]=u.second;
        }
    }
    fu(k,1,n)
    {
        fu(i,1,n)
        {
            fu(j,1,n)
            {
                if(d[i][j]<d[i][k]*d[k][j]&&d[k][j]!=-1&&d[i][k]!=-1)
                {
                    d[i][j]=d[i][k]*d[k][j];
                    //cout<<i<<" "<<j<<" "<<k<<" "<<d[i][k]<<" "<<d[k][j]<<" "<<d[i][j]<<endl;
                }
            }
        }
    }
    fu(i,1,n)
    {
        //cout<<d[1][i]<<endl;
    }
    //cout<<d[1][n]<<endl;
}
int main()
{
    ll n,m,u,v,i,w;
    while(1)
    {
        sl(n);
        if(n==0)
        {
            break;
        }
        sl(m);
        fu(i,1,m)
        {
            sl(u);
            sl(v);
            sl(w);
            double w1=w/100.0;
            adj[u].pb(mp(v,w1));
            adj[v].pb(mp(u,w1));
        }
        floyd_warshall(n);
        printf("%.6lf percent\n",100*d[1][n]);
        fu(i,1,n)
        {
            adj[i].clear();
        }
    }
    return 0;
}