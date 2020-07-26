//Problem link https://www.codechef.com/problems/CHEFDIV
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
#define N 1000005
using namespace std;
ll arr[N];
vector<ll> pr;
vector <pll> pf[N];

struct cmp {
    bool operator()(const pll &a, const pll &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

void pre() {
    ll i, j;
    fu(i, 2, 1e6) {
        if (!arr[i]) {
            pr.pb(i);
            for (j = i * i; j <= 1e6; j += i) {
                arr[j] = 1;
            }
        }
    }
    arr[1] = arr[0] = 1;
}

ll solve(ll a, ll b) {
    ll low = a, high = b;
    ll i, j, x, c;
    for (i = 0; i < pr.size() && pr[i] <= high; i++) {
        ll sl = (low / pr[i]) * pr[i];
        //cout<<pr[i]<<" "<<sl<<endl;
        if (sl < low) {
            sl += pr[i];
        }
        for (j = sl; j <= high; j += pr[i]) {
            x = j;
            c = 0;
            while (x % pr[i] == 0) {
                x /= pr[i];
                c++;
            }
            if (c > 0) {
                pf[j - low].pb(mp(pr[i], c));
            }
        }
    }
    fu(i, low, high) {
        x = i;
        rep(j, pf[i - low].size()) {
            while (x % pf[i - low][j].first == 0) {
                x /= pf[i - low][j].first;
            }
        }
        if (x > 1) {
            //cout<<x<<endl;
            pf[i - low].pb(mp(x, 1));
        }
    }
    ll ans = 0;
    fu(i, low, high) {
        /*cout<<i<<" : ";
        rep(j,pf[i-low].size())
        {
            cout<<pf[i-low][j].first<<" "<<pf[i-low][j].second<<"    ";
        }
        cout<<endl;*/
        if (pf[i - low].size() == 0 && low != 1) {
            ans += 2;
            continue;
        }
        ll tmpans = 0;
        ll pr = 1;
        priority_queue < pll, vector < pll >, cmp > pq;
        rep(j, pf[i - low].size()) {
            pr *= (pf[i - low][j].second + 1);
            pq.push(pf[i - low][j]);
        }
        tmpans += pr - 1;
        //cout<<pr<<" ** ";
        while (!pq.empty()) {
            pll p = pq.top();
            pq.pop();
            pr /= (p.second + 1);
            pr *= p.second;
            if (p.second > 1) {
                p.second--;
                pq.push(p);
            }
            tmpans += pr;
            //cout<<pr<<" ** ";
        }
        ans += tmpans;
    }
    return ans;
}

int main() {
    pre();
    ll a, b;
    sl(a);
    sl(b);
    pl(solve(a, b));
    pn();
    return 0;
}