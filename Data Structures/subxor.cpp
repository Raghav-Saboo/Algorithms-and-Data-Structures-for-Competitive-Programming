//Problem Link http://www.spoj.com/problems/SUBXOR/
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
struct trie
{
    trie *c[2];
    ll lc,rc;
    trie()
    {
        lc=rc=0;
        c[0]=c[1]=NULL;
    }
};
ll arr[N];
trie  *insert(trie *root,ll x)
{
    ll i;
    trie *tmp=root;
    fd(i,31,0)
    {
        ll r=(x>>i)&1;
        if(tmp->c[r]==NULL)
        {
            tmp->c[r]=new trie();
        }
        if(r==0)
        {
            (tmp->lc)++;
        }
        else
        {
            (tmp->rc)++;
        }
        tmp=tmp->c[r];
    }
    return root;
}
ll query(trie *root,ll q,ll k)
{
    ll i,x=0;
    trie *tmp=root;
    fd(i,31,0)
    {
        ll bq=(q>>i)&1;
        ll bk=(k>>i)&1;
        if(bq==1&&bk==1)
        {
            x+=tmp->rc;
            tmp=tmp->c[0];
            if(tmp==NULL)
            {
                return x;
            }
        }
        else if(bq==1&&bk==0)
        {
            tmp=tmp->c[1];
            if(tmp==NULL)
            {
                return x;
            }
        }
        else if(bq==0&&bk==0)
        {
            tmp=tmp->c[0];
            if(tmp==NULL)
            {
                return x;
            }
        }
        else
        {
            x+=tmp->lc;
            tmp=tmp->c[1];
            if(tmp==NULL)
            {
                return x;
            }
        }
    }
    return x;
}
int main()
{
    ll t,n,k,i,ans,p,q;
    trie *root;
    sl(t);
    while(t--)
    {
        root=new trie();
        sl(n);sl(k);
        fu(i,1,n)
        {
            sl(arr[i]);
        }
        ans=0;
        root=insert(root,0);
        p=0;
        fu(i,1,n)
        {
            q=p^arr[i];
            ans+=query(root,q,k);
            root=insert(root,q);
            p=q;
        }
        pl(ans);pn();
    }
    return 0;   
}