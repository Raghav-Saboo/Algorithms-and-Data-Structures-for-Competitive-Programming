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

struct node {
    ll val;
    node *left, *right;

    node(ll val, node *left, node *right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

node *root[N];
node *null = new node(1e10, NULL, NULL);

node *build(ll rl, ll rr) {
    if (rl == rr) {
        return new node(arr[rl], null, null);
    }
    ll mid = (rl + rr) / 2;
    node *p = build(rl, mid);
    node *q = build(mid + 1, rr);
    return new node(min(p->val, q->val), p, q);
}

ll query(node *root, ll ql, ll qr, ll rl, ll rr) {
    if (ql > rr || rl > qr || ql > qr) {
        return 1e10;
    }
    if (ql <= rl && rr <= qr) {
        return root->val;
    }
    ll mid = (rl + rr) / 2;
    return min(query(root->left, ql, qr, rl, mid), query(root->right, ql, qr, mid + 1, rr));
}

node *update(node *prev, ll id, ll val, ll rl, ll rr) {
    if (rl <= id && id <= rr) {
        if (rl == rr) {
            return new node(val, null, null);
        }
        ll mid = (rl + rr) / 2;
        node *p = update(prev->left, id, val, rl, mid);
        node *q = update(prev->right, id, val, mid + 1, rr);
        return new node(min(p->val, q->val), p, q);
    }
    return prev;
}

int main() {
    null->left = null->right = null;
    ll n, q, i, l, r, id, val;
    char ch;
    ll cnt = 0;
    sl(n);
    sl(q);
    fu(i, 1, n) {
        sl(arr[i]);
    }
    root[++cnt] = build(1, n);
    while (q--) {
        cin >> ch;
        if (ch == 'u') {
            sl(id);
            sl(val);
            root[cnt + 1] = update(root[cnt], id, val, 1, n);
            cnt++;
        } else {
            sl(l);
            sl(r);
            pl(query(root[cnt], l, r, 1, n));
            pn();
        }
    }
    return 0;
}