//RMQ
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
ll arr[N];
struct node
{
    ll min;
};
struct node seg[4*N];
void build(ll rl,ll rr,ll id)
{
    if(rl==rr)
    {
        seg[id].min=arr[rl];
        return;
    }
    ll mid=(rl+rr)/2;
    build(rl,mid,2*id);
    build(mid+1,rr,2*id+1);
    seg[id].min=min(seg[2*id].min,seg[2*id+1].min);
}
ll query(ll ql,ll qr,ll rl,ll rr,ll id)
{
    if(ql>rr||rl>qr||ql>qr)
    {
        return 1e8;
    }
    if(ql<=rl&&rr<=qr)
    {
        return seg[id].min;
    }
    ll mid=(rl+rr)/2;
    return min(query(ql,qr,rl,mid,2*id),query(ql,qr,mid+1,rr,2*id+1));
}
void update(ll indu,ll v,ll rl,ll rr,ll id)
{
    if(rl<=indu&&indu<=rr)
    {
        if(rl==rr)
        {
            seg[id].min=v;
            return;
        }
        ll mid=(rl+rr)/2;
        update(indu,v,rl,mid,2*id);
        update(indu,v,mid+1,rr,2*id+1);
        seg[id].min=min(seg[2*id].min,seg[2*id+1].min);
    }
}
int main()
{
    ll n,q,l,r,x,ans,id,i;
    char ch;
    sl(n);
    sl(q);
    fu(i,1,n)
    {
        sl(arr[i]);
    }
    build(1,n,1);
    while(q--)
    {
        cin>>ch;
        if(ch=='q')
        {
            sl(l);sl(r);
            pl(query(l,r,1,n,1));pn();
        }
        else
        {
            sl(id);sl(x);
            arr[id]=x;
            update(id,x,1,n,1);
        }
    }
    return 0;
}