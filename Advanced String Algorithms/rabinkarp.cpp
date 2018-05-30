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
ll mexp(ll a,ll b,ll c)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)
        {
            res*=a;
            res%=c;
        }
        a=(a*a)%c;
        b/=2;
    }
    return res;
}
int main()
{
    string txt,pat;
    ll t,i,n,m,p,s,q,d,h;
    ll ans;
    //sl(t);
    //while(t--)
    while(sl(m)!=EOF)
    {
        cin>>pat>>txt;
        n=txt.size();
        m=pat.size();
        q=1e9+7;
        d=26;
        h=mexp(d,m-1,q);
        p=0;
        ll tmp1,tmp2;
        tmp1=0;
        rep(i,m)
        {
            p=(d*p+(pat[i]-'a'))%q;
            tmp1=(d*tmp1+(txt[i]-'a'))%q;
        }
        fu(s,0,n-m)
        {
            //cout<<p<<" "<<tmp1<<endl;
            if(p==tmp1)
            {
                //cout<<s<<endl;
                if(pat.compare(txt.substr(s,m))==0)
                {
                    pl(s);pn();
                }
            }
            if(s<n-m)
            {
                tmp2=(d*(tmp1-(txt[s]-'a')*h+q)%q+(txt[s+m]-'a')+q)%q;
                tmp1=tmp2;
            }
        }
        //pn();
    }
    return 0;
}