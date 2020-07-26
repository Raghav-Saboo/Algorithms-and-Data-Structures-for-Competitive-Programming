//Problem Link https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2683
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

struct trie {
    trie *c[2];

    trie() {
        c[0] = c[1] = NULL;
    }
};

ll arr[N];

trie *insert(trie *root, ll x) {
    ll i;
    trie *tmp = root;
    fd(i, 31, 0) {
        ll r = (x >> i) & 1;
        if (tmp->c[r] == NULL) {
            tmp->c[r] = new trie();
        }
        tmp = tmp->c[r];
    }
    return root;
}

ll query(trie *root, ll x) {
    ll i, ans = 0;
    trie *tmp = root;
    fd(i, 31, 0) {
        ll r = (x >> i) & 1;
        if (tmp->c[r ^ 1] != NULL) {
            ans += (1 << i);
            tmp = tmp->c[r ^ 1];
        } else if (tmp->c[r] != NULL) {
            tmp = tmp->c[r];
        }
    }
    return ans;
}

int main() {
    ll t, n, k, i, ans, p, q;
    trie *root;
    sl(t);
    while (t--) {
        root = new trie();
        sl(n);
        fu(i, 1, n) {
            sl(arr[i]);
        }
        ans = 0;
        root = insert(root, 0);
        p = 0;
        fu(i, 1, n) {
            q = p ^ arr[i];
            ans = max(ans, query(root, q));
            root = insert(root, q);
            p = q;
        }
        pl(ans);
        pn();
    }
    return 0;
}