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
#define N 105
ll dp[N][N];
ll freq[105];
ll keys[105];
ll arr[N];
ll dir[N][N];
ll pref_freq[N];
void print(ll i,ll j)
{
    if(i>j)
    {
        return;
    }
    else if(i==j)
    {
        cout<<keys[i]<<" ";
    }
    else
    {
        cout<<keys[dir[i][j]]<<" ";
        print(i,dir[i][j]-1);
        //cout<<keys[dir[i][j]]<<" ";
        print(dir[i][j]+1,j);
        //cout<<keys[dir[i][j]]<<" ";
    }
}
void optimal_bst(ll n)
{
    ll i,j,k,l;
    pref_freq[1]=freq[1];
    fu(i,2,n)
    {
        pref_freq[i]=pref_freq[i-1]+freq[i];
    }
    ll ans;
    fu(i,1,n)
    {
        fu(j,1,n)
        {
            dp[i][j]=1e10;
        }
    }
    fu(i,1,n)
    {
        dp[i][i]=freq[i];
    }
    fu(i,1,n-1)
    {
        dp[i][i+1]=freq[i]+freq[i+1]+min(dp[i][i],dp[i+1][i+1]);
        if(dp[i][i+1]==freq[i]+freq[i+1]+dp[i][i])
        {
            dir[i][i+1]=i;
        }
        else
        {
            dir[i][i+1]=i+1;
        }
    }
    fu(l,2,n)
    {
        fu(i,1,n-l+1)
        {
            j=i+l-1;
            ll ans=1e10;
            fu(k,i,j)
            {
                if(ans>pref_freq[j]-pref_freq[i-1]+dp[i][k-1]+dp[k+1][j])
                {
                    dir[i][j]=k;
                }
                ans=min(ans,pref_freq[j]-pref_freq[i-1]+dp[i][k-1]+dp[k+1][j]);
            }
            dp[i][j]=ans;
        }
    }
    ans=dp[1][n];
    pl(ans);pn();
    print(1,n);pn();
}
int main()
{
    ll t,n,i;
    sl(t);
    while(t--)
    {
        sl(n);
        fu(i,1,n)
        {
            sl(keys[i]);
        }
        fu(i,1,n)
        {
            sl(freq[i]);
        }
        optimal_bst(n);
    }
    return 0;
}