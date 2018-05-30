//Problem Link http://www.spoj.com/problems/RMQSQ/
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
#define lgn 30
ll arr[N];
ll st[N][lgn];
void build_sparse_table(ll n)
{
    ll i,j;
    fu(i,1,n)
    {
        st[i][0]=arr[i];
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i+(1<<j)-1<=n;i++)
        {
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(ll l,ll r)
{
    ll k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    ll n,q,i,l,r,ans;
    sl(n);
    fu(i,1,n)
    {
        sl(arr[i]);
    }
    build_sparse_table(n);
    sl(q);
    while(q--)
    {
        sl(l);
        sl(r);
        l++;
        r++;
        pl(query(l,r));pn();
    }
    return 0;
}