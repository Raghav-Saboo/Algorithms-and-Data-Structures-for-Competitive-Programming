//Problem Link https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/akash-and-gcd-1-16/
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
ll bit1[N];
ll bit2[N];
void upd(ll id,ll v,ll n,ll bi)
{
    if(id==0)
    {
        return;
    }
    while(id<=n)
    {
        //cout<<id<<endl;
        if(bi==1)
        {
            bit1[id]+=v;
        }
        else
        {
            bit2[id]+=v;
        }
        id+=(id&-id);
    }
}
ll query(ll id,ll bi)
{
    ll s=0;
    while(id>0)
    {
        //cout<<id<<endl;
        if(bi==1)
        {
            s+=bit1[id];
        }
        else
        {
            s+=bit2[id];
        }
        id-=(id&-id);
    }
    return s;
}
ll get_ans(ll id)
{
    return query(id,1)*id-query(id,2);
}
int main()
{
    ll ty;
    ll t,n,q,l,r,ans,i,v;
    sl(t);
    while(t--)
    {
        sl(n);sl(q);
        while(q--)
        {
            sl(ty);
            if(ty==0)
            {
                sl(l);sl(r);sl(v);
                upd(l,v,n,1);
                upd(r+1,-v,n,1);
                upd(l,v*(l-1),n,2);
                upd(r+1,-v*r,n,2);
            }
            else
            {
                sl(l);sl(r);
                ans=get_ans(r)-get_ans(l-1);
                pl(ans);pn();
            }
        }
        fu(i,1,n)
        {
            bit1[i]=bit2[i]=0;
        }
    }
    return 0;
}