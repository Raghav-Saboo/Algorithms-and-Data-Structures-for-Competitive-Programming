//Problem link https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/mergesort/
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
ll merge(ll left[],ll right[],ll arr[],ll l,ll r,ll n)
{
    ll i,j,k;
    i=1;
    j=1;
    k=1;
    ll ans=0;
    while(i<=l&&j<=r)
    {
        if(left[i]<=right[j])
        {
            arr[k++]=left[i++];
            ans+=j-1;
        }
        else
        {
            arr[k++]=right[j++];
        }
    }
    while(i<=l)
    {
        arr[k++]=left[i++];
        ans+=j-1;
    }
    while(j<=r)
    {
        arr[k++]=right[j++];
    }
    return ans;
}
ll merge_sort(ll arr[],ll n)
{
    if(n<2)
    {
        return 0;
    }
    ll i,mid=n/2;
    ll left[mid+1];
    ll right[n-mid+1];
    fu(i,1,mid)
    {
        left[i]=arr[i];
    }
    fu(i,mid+1,n)
    {
        right[i-mid]=arr[i];
    }
    ll ans=0;
    ans+=merge_sort(left,mid);
    ans+=merge_sort(right,n-mid);
    ans+=merge(left,right,arr,mid,n-mid,n);
    return ans;
}
int main()
{
    ll n,i;
    sl(n);
    fu(i,1,n)
    {
        sl(arr[i]);
    }
    pl(merge_sort(arr,n));
    pn();
    return 0;
}
