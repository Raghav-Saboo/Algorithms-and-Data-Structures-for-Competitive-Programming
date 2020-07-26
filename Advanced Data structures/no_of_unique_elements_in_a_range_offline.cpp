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
#define N 100005
ll arr[N];
ll bit[N];
ll tmp[N];
struct qu {
    ll l;
    ll r;
    ll id;
};
struct qu query[2 * N];
ll ans[2 * N];

int cmp(qu a, qu b) {
    return a.r < b.r;
}

void upd(ll id, ll v, ll n) {
    while (id <= n) {
        bit[id] += v;
        id += (id & -id);
    }
}

ll query_bit(ll id) {
    ll s = 0;
    while (id > 0) {
        s += bit[id];
        id -= (id & -id);
    }
    return s;
}

int main() {
    ll n, i, j, x, y, t, q, l, r, id, tc = 0;
    //sl(t);
    //while(t--)
    {
        map<ll, ll> fp, rp;
        sl(n);
        //scanf("%lld %lld",&n,&q);
        fu(i, 1, n) {
            sl(arr[i]);
            fp[arr[i]]++;
        }
        i = 0;
        for (map<ll, ll>::iterator it = fp.begin(); it != fp.end(); it++) {
            rp[it->first] = ++i;
        }
        sl(q);
        fu(i, 1, q) {
            scanf("%lld %lld", &query[i].l, &query[i].r);
            //sl(query[i].l);sl(query[i].r);
            query[i].id = i;
        }
        fu(i, 1, n) {
            arr[i] = rp[arr[i]];
        }
        fu(i, 1, n) {
            tmp[i] = -1;
            bit[i] = 0;
        }
        sort(query + 1, query + 1 + q, cmp);
        ll cnt = 1;
        fu(i, 1, n) {
            if (tmp[arr[i]] != -1) {
                upd(tmp[arr[i]], -1, n);
            }
            tmp[arr[i]] = i;
            upd(i, 1, n);
            while (cnt <= q && query[cnt].r == i) {
                ans[query[cnt].id] = query_bit(query[cnt].r) - query_bit(query[cnt].l - 1);
                cnt++;
                //cout<<cnt<<" "<<i<<endl;
            }
        }
        //printf("Case %lld:\n",++tc);
        fu(i, 1, q) {
            pl(ans[i]);
            pn();
        }
    }
    return 0;
} 