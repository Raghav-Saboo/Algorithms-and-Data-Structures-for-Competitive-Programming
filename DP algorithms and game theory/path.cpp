//GFG Practice
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
#define N 25
ll arr[N][N];
int main()
{
    ll t,n,i,j;
    ll ans;
    sl(t);
    while(t--)
    {
        sl(n);
        fu(i,1,n)
        {
            fu(j,1,n)
            {
                sl(arr[i][j]);
            }
        }
        ans=0;
        fd(i,n-1,1)
        {
            fu(j,1,n)
            {
                ll mx=0;
                if(i+1<=n&&j+1<=n)
                {
                    mx=max(mx,arr[i+1][j+1]);
                }
                if(i+1<=n)
                {
                    mx=max(mx,arr[i+1][j]);
                }
                if(i+1<=n&&j-1>=0)
                {
                    mx=max(mx,arr[i+1][j-1]);
                }
                arr[i][j]+=mx;
            }
        }
        fu(i,1,n)
        {
            ans=max(ans,arr[1][i]);
        }
        pl(ans);pn();
    }
    return 0;
}