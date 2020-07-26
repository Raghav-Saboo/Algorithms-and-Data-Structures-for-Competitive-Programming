#include <bits/stdc++.h>

using namespace std;
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
#define N 100005
ll arr[N];
ll top = -1;

void push(ll x) {
    arr[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "No Food\n";
        return;
    }
    ll tmp = arr[top];
    top--;
    cout << tmp << endl;
}

int main() {
    ll q, ty;
    sl(q);
    while (q--) {
        sl(ty);
        if (ty == 1) {
            pop();
        } else {
            ll c;
            sl(c);
            push(c);
        }
    }
    return 0;
}