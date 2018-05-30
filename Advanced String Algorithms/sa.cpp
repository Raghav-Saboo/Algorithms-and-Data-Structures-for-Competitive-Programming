//Problem link 
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
#define LGN 30
ll Ps[LGN][N],Sa[N];
struct entry
{
    pll val;
    ll index;
};
entry Ls[N],b[N];
int cmp(entry a,entry b)
{
    if(a.val.fi!=b.val.fi)
    {
        return a.val.fi<b.val.fi;
    }
    else
    {
        return a.val.se<b.val.se;
    }
}
ll lcp(ll x,ll y,ll step,ll n)
{
    ll k,ans=0;
    if(x==y)
    {
        return n-x;
    }
    for(k=step;k>=0&&x<n&&y<n;k--)
    {
        if(Ps[k][x]==Ps[k][y])
        {
            ans+=(1<<k);
            x+=(1<<k);
            y+=(1<<k);
        }
    }
    return ans;
}
void counting_sort(ll n,ll id)
{
    ll mx=0,i;
    rep(i,n)
    {
        mx=max(mx,((id==1)?Ls[i].val.fi:Ls[i].val.se)+1);
    }
    ll cnt[mx+5];
    fu(i,0,mx)
    {
        cnt[i]=0;
    }
    rep(i,n)
    {
        cnt[((id==1)?Ls[i].val.fi:Ls[i].val.se)+1]++;
    }
    fu(i,1,mx)
    {
        cnt[i]+=cnt[i-1];
    }
    fd(i,n-1,0)
    {
        b[cnt[((id==1)?Ls[i].val.fi:Ls[i].val.se)+1]-1]=Ls[i];
        cnt[((id==1)?Ls[i].val.fi:Ls[i].val.se)+1]--;
    }
    rep(i,n)
    {
        Ls[i]=b[i];
        //pl(Ls[i].val.fi);ps();pl(Ls[i].val.se);ps();ps();
    }
}  
void radix_sort(ll n)
{
    //pl(n);pn();
    counting_sort(n,2);
    //pl(n);pn();
    counting_sort(n,1);
}
int main()
{
    ll t,n,i,j,ans,step,cnt;
    //sl(t);
    //while(t--)
    {
        string s;
        cin>>s;
        n=s.size();
        map <char,int> cp,rp;
        rep(i,n)
        {
            cp[s[i]]++;
        }
        i=0;
        for(map<char,int>::iterator it=cp.begin();it!=cp.end();it++)
        {
            rp[it->first]=i++;
        }
        rep(i,n)
        {
            Ps[0][i]=rp[s[i]];
        }
        for(step=1,cnt=1;(cnt>>1)<n;step++,cnt=cnt<<1)
        {
            rep(i,n)
            {
                Ls[i].index=i;
                Ls[i].val.fi=Ps[step-1][i];
                Ls[i].val.se=(i+cnt)<n?Ps[step-1][i+cnt]:-1;
            }
            //pl(n);pn();
            radix_sort(n);
            //sort(Ls,Ls+n,cmp);
            rep(i,n)
            {
                Ps[step][Ls[i].index]=(i>0&&Ls[i].val.fi==Ls[i-1].val.fi&&Ls[i].val.se==Ls[i-1].val.se)?Ps[step][Ls[i-1].index]:i;
            }
            rep(i,n)
            {
              //  pl(Ls[i].val.fi);ps();pl(Ls[i].val.se);ps();ps();
            }
            //pn();
        }
        step--;
        rep(i,n)
        {
            Sa[Ps[step][i]]=i;
            //pl(Ps[step][i]);pn();
        }
        rep(i,n)
        {
            pl(Sa[i]);
            pn();
        }
    }
    return 0;
}