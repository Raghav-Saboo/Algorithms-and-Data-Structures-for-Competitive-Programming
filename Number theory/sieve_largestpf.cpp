//Codebuddy Practice
#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i, a, n) for(i=a;i<=n;i++)
#define fd(i, a, n) for(i=a;i>=n;i--)
#define rep(i, n)  for(i=0;i<n;i++)
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
#define N 10000005
using namespace std;
ll hp[N], ans[N], arr[N];

void pre() {
    ll i, j;
    fu(i, 2, 1e7) {
        if (!arr[i]) {
            hp[i] = i;
            for (j = i * 2; j <= 1e7; j += i) {
                hp[j] = i;
                arr[j] = 1;
            }
        }
    }
    fu(i, 2, 1e7) {
        ans[i] = ans[i - 1] + hp[i];
    }
}

int main() {
    pre();
    ll t, a, b, an;
    sl(t);
    while (t--) {
        sl(a);
        an = ans[a];
        pl(an);
        pn();
    }
    return 0;
}