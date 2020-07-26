//Problem Link http://www.spoj.com/problems/DQUERY/
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
#define N 30005
ll BS = sqrt(N);
ll arr[N];
ll freq[1000005];
struct qu {
    ll l;
    ll r;
    ll id;
};
ll ans[200005];
struct qu query[200005];

int cmp(struct qu a, struct qu b) {
    if (a.l / BS != b.l / BS) {
        return a.l / BS < b.l / BS;
    }
    return a.r < b.r;
}

void add(ll pos, ll &an) {
    if (pos == 0)return;
    freq[arr[pos]]++;
    if (freq[arr[pos]] == 1) {
        an++;
    }
}

void remove(ll pos, ll &an) {
    if (pos == 0)return;
    freq[arr[pos]]--;
    if (freq[arr[pos]] == 0) {
        an--;
    }
}

int main() {
    ll n, i, q, l, r;
    sl(n);
    fu(i, 1, n) {
        sl(arr[i]);
    }
    sl(q);
    fu(i, 1, q) {
        sl(l);
        sl(r);
        query[i].l = l;
        query[i].r = r;
        query[i].id = i;
    }
    sort(query + 1, query + 1 + q, cmp);
    ll cl, cr;
    cl = 1;
    cr = 1;
    ll an = 0;
    fu(i, 1, q) {
        l = query[i].l;
        r = query[i].r;
        while (cl > l) {
            cl--;
            add(cl, an);
        }
        while (cr <= r) {
            add(cr, an);
            cr++;
        }
        while (cl < l) {
            remove(cl, an);
            cl++;
        }
        while (cr - 1 > r) {
            remove(cr - 1, an);
            cr--;
        }
        ans[query[i].id] = an;
    }
    fu(i, 1, q) {
        pl(ans[i]);
        pn();
    }
    return 0;
}