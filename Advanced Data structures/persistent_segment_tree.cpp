//Problem Link http://www.spoj.com/problems/MKTHNUM/
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
ll arr[N];
struct node
{
    ll count;
    struct node *left,*right;
    node(ll count,node *left,node *right)
    {
        this->count=count;
        this->left=left;
        this->right=right;
    }
};
node *root[N];
map <ll,ll> fm,rm;
node *null=new node(0,NULL,NULL);
node *insert(ll rl,ll rr,ll val,node *root)
{
    if(rl<=val&&val<=rr)
    {    
        if(rl==rr)
        {
            return new node(1,null,null);
        }
        ll mid=(rl+rr)/2;
        node *p=insert(rl,mid,val,root->left);
        node *q=insert(mid+1,rr,val,root->right);
        return new node(p->count+q->count,p,q);
    }
    return root;
}
ll query(node *a,node *b,ll rl,ll rr,ll k)
{
    if(rl==rr)
    {
        return rl;
    }
    ll count=a->left->count-b->left->count;
    ll mid=(rl+rr)/2;
    if(count>=k)
    {   
        return query(a->left,b->left,rl,mid,k);
    }
    else
    {
        return query(a->right,b->right,mid+1,rr,k-count);
    }
}
int main()
{
    ll n,q,l,r,i,k;
    sl(n);sl(q);
    fu(i,1,n)
    {
        sl(arr[i]);
        fm[arr[i]]++;
    }
    i=0;
    for(map<ll,ll> :: iterator it=fm.begin();it!=fm.end();it++)
    {
        fm[it->first]=++i;
        rm[i]=it->first;
    }
    null->left=null->right=null;
    ll maxi=i;
    fu(i,1,n)
    {
        root[i]=insert(1,maxi,fm[arr[i]],(i==1?null:root[i-1]));
    }
    while(q--)
    {
        sl(l);sl(r);sl(k);
        pl(rm[query(root[r],(l>1?root[l-1]:null),1,maxi,k)]);pn();
    }
    return 0;
}