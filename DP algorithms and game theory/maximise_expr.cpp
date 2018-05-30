//Problem link  http://www.spoj.com/problems/LISA/
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
#define N 505
ll dp[N][N][2];
ll dir[N][N];
ll val[N];
char oper[N];
void print(ll i,ll j)
{
    if(j==i+1)
    {
        cout<<"("<<val[i]<<oper[i]<<val[j]<<")";
    }
    else if(i==j)
    {
        cout<<val[i];
    }
    else if(i>=1&&j>=1)
    {
        cout<<"(";
        print(i,dir[i][j]);
        cout<<oper[dir[i][j]];
        print(dir[i][j]+1,j);
        cout<<")";
    }
}
void mcm(ll n)
{
    ll i,j,k,l;
    fu(i,1,n)
    {
        fu(j,1,n)
        {
            dir[i][j]=0;
            dp[i][j][0]=dp[i][j][1]=1e10;
        }
    }
    fu(i,1,n)
    {
        dp[i][i][0]=val[i];
        dp[i][i][1]=val[i];
    }
    fu(i,1,n-1)
    {
        if(oper[i]=='+')
        {
            dp[i][i+1][0]=val[i]+val[i+1];
            dp[i][i+1][1]=val[i]+val[i+1];            
        }
        else
        {
            dp[i][i+1][0]=val[i]*val[i+1];
            dp[i][i+1][1]=val[i]*val[i+1];                        
        }
    }
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            ll mn=1e10;
            ll mx=0;
            for(k=i;k<j;k++)
            {
                if(oper[k]=='+')
                {
                    mn=min(mn,dp[i][k][0]+dp[k+1][j][0]);
                    if(mx<dp[i][k][1]+dp[k+1][j][1])
                    {
                        dir[i][j]=k;
                    }
                    mx=max(mx,dp[i][k][1]+dp[k+1][j][1]);
                }
                else
                {   
                    mn=min(mn,dp[i][k][0]*dp[k+1][j][0]);
                    if(mx<dp[i][k][1]*dp[k+1][j][1])
                    {
                        dir[i][j]=k;
                    }
                    mx=max(mx,dp[i][k][1]*dp[k+1][j][1]);
                }
            }
            dp[i][j][0]=mn;
            dp[i][j][1]=mx;
        }
    }
    pl(dp[1][n][1]);ps();pl(dp[1][n][0]);pn();
    print(1,n);
}
int main()
{
    string s;
    ll t,n,i;
    sl(t);
    while(t--)
    {
        cin>>s;
        ll l=s.size();
        ll j=0,k=0;
        rep(i,l)
        {
            if(i%2!=0)
            {
                oper[++j]=s[i];
            }
            else
            {
                val[++k]=s[i]-'0';
            }
        }
        mcm(k);
    }
    return 0;
}