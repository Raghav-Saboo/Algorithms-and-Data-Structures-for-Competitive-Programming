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
// always remember that strict ordering is required so never use a<=b instead use a<b or b>a
struct cmp
{
  bool operator()(int a,int b)
  {
    return a>b; // to sort in ascending order, use a<b for descending order
  }
};
int main()
{
  priority_queue <ll,vector<ll>,cmp> pq;
  ll i,n,x;
  sl(n);
  fu(i,1,n)
  {
    sl(x);
    pq.push(x);
  }
  while(!pq.empty())
  {
    cout<<pq.top()<<endl;
    pq.pop();
  }
}
