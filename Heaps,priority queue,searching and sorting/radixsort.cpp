//Problem link https://www.hackerearth.com/practice/
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
#define N 1005
ll arr[N],b[N];
ll c[15];
void stable_sort(ll x,ll n)
{
    ll i;
    fu(i,0,9)
    {
        c[i]=0;
    }
    fu(i,1,n)
    {
        c[(arr[i]/x)%10]++;
    }
    fu(i,1,9)
    {
        c[i]+=c[i-1];
    }
    fd(i,n,1)
    {
        b[c[(arr[i]/x)%10]]=arr[i];
        c[(arr[i]/x)%10]--;
    }
    fu(i,1,n)
    {
        arr[i]=b[i];
        pl(arr[i]);ps();
    }
    pn();
}
void radix_sort(ll n,ll k)
{
    ll x=1;
    while(k>0)
    {
        //cout<<x<<" "<<n<<endl;
        stable_sort(x,n);
        x*=10;
        k/=10;
    }    
}
int main()
{
    ll n,i,j,x,k=0;
    sl(n);
    fu(i,1,n)
    {
        sl(arr[i]);
        k=max(k,arr[i]);
    }
    radix_sort(n,k);
    return 0;
}