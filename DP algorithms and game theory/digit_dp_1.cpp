//Problem link  http://www.spoj.com/problems/GONE/
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
ll dp[10][2][120];
ll ispr[205];

void pre() {
    ll i, j;
    ispr[0] = ispr[1] = 1;
    fu(i, 2, 200) {
        if (!ispr[i]) {
            for (j = i * i; j <= 200; j += i) {
                ispr[j] = 1;
            }
        }
    }
}

string tostring(ll n) {
    string s = "";
    while (n > 0) {
        s += (n % 10) + '0';
        n /= 10;
    }
    reverse(all(s));
    return s;
}

ll check(ll sod) {
    if (!ispr[sod]) {
        return 1;
    }
    return 0;
}

ll solve(string s, ll smaller, ll index, ll sod) {
    if (dp[index][smaller][sod] != -1) {
        return dp[index][smaller][sod];
    }
    if (index == s.size()) {
        return check(sod);
    }
    ll i, limit = 9;
    if (smaller) {
        limit = s[index] - '0';
    }
    ll ic = 0;
    for (i = 0; i <= limit; i++) {
        ll ns;
        if (i < limit) {
            ns = 0;
        } else {
            ns = smaller;
        }
        ic += solve(s, ns, index + 1, sod + i);
    }
    dp[index][smaller][sod] = ic;
    return ic;
}

int main() {
    pre();
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t, n, r, l, k, ans;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        memset(dp, -1, sizeof(dp));
        //cout<<tostring(r)<<" "<<solve(tostring(r),1,0,0,0,k)<<" "<<solve(tostring(r-1),1,0,0,0,k)<<endl;
        ans = solve(tostring(r), 1, 0, 0);
        memset(dp, -1, sizeof(dp));
        ans -= solve(tostring(l - 1), 1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}