//Problem link https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
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
ll arr[N];
void max_heapify(ll id,ll n)
{
    ll l,r,largest;
    l=2*id;
    r=2*id+1;
    if(l<=n&&arr[l]>arr[id])
    {
        largest=l;
    }
    else
    {
        largest=id;
    }
    if(r<=n&&arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=id)
    {
        ll tmp=arr[largest];
        arr[largest]=arr[id];
        arr[id]=tmp;
        max_heapify(largest,n);
    }
}
ll extract_max(ll &n)
{
    if(n<1)
    {
        return -1;
    }
    ll mx=arr[1];
    arr[1]=arr[n];
    n--;
    max_heapify(1,n);
    return mx;
}
void heap_increase_key(ll id,ll n,ll key)
{
    arr[id]=key;
    while(id>1&&arr[id/2]<arr[id])
    {
        ll tmp=arr[id];
        arr[id]=arr[id/2];
        arr[id/2]=tmp;
        id/=2;
    }
}   
void insert(ll key,ll &n)
{
    arr[++n]=-1e10;
    heap_increase_key(n,n,key);
}
int main()
{
    ll n,i,j,x,ans;
    sl(n);
    ll hs=0;
    fu(i,1,n)
    {
        sl(x);
        insert(x,hs);
        if(hs<3)
        {
            ans=-1;
        }
        else
        {
            ll mx1=extract_max(hs);
            ll mx2=extract_max(hs);
            ll mx3=extract_max(hs);
            ans=mx1*mx2*mx3;
            insert(mx1,hs);
            insert(mx2,hs);
            insert(mx3,hs);
        }
        pl(ans);
        pn();
    }
    return 0;
}