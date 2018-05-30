//Problem link https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/practice-problems/algorithm/longest-palindromic-string/
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
#define N 200005
ll T[N];
void manchar_algo(string txt)
{
    ll n,l,start,end,i,id,j;
    int new_center;
    n=txt.size();
    string ntxt;
    l=2*n+1;
    id=0;
    rep(i,l)
    {
        if(i%2!=0)
        {
            ntxt+=txt[id++];
        }
        else
        {
            ntxt+="$";
        }
    }
    //cout<<ntxt<<endl;
    start=0;
    end=0;
    for(i=0;i<l;)
    {
        while(start>0&&end<l-1&&ntxt[start-1]==ntxt[end+1])
        {
            start--;
            end++;
        }
        T[i]=end-start+1;
        //cout<<i<<" "<<start<<" "<<end<<" "<<T[i]<<endl;
        if(end==l-1)
        {
            break;
        }
        new_center=end+ ( (i%2==0) ? 1 : 0 );
        fu(j,i+1,end)
        {
            T[j]=min(T[i-(j-i)],(end-j)*2+1);
            if(j+T[i-(j-i)]==end)
            {
                new_center=j;
                break;
            }
        }
        i=new_center;
        start=i-T[i]/2;
        end=i+T[i]/2;
    }
    ll ans=0;
    id=0;
    rep(i,l)
    {
        //cout<<i<<" "<<T[i]<<endl;
        if(T[i]>ans)
        {
            ans=T[i];
            id=i;
        }
    }
    ans/=2;
    pl(ans);
    pn();
    //cout<<id<<endl;
    if(ntxt[id]=='$')
    {
        cout<<txt.substr(id/2-ans/2,ans)<<endl;
    }
    else
    {
        cout<<txt.substr(id/2-(ans/2),ans)<<endl;
    }
}
int main()
{
    string txt;
    cin>>txt;
    manchar_algo(txt);
    return 0;
}