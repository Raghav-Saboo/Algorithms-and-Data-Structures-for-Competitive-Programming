//GFG Practice
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
#define N 5005
ll dp[N][N];
char dir[N][N];

void print_lcs(string s, ll i, ll j) {
    if (i <= 0 || j <= 0) {
        return;
    }
    if (dir[i][j] == 'd') {
        print_lcs(s, i - 1, j - 1);
        cout << s[i - 1];
    } else if (dir[i][j] == 'u') {
        print_lcs(s, i - 1, j);
    } else {
        print_lcs(s, i, j - 1);
    }
}

void lcs(string a, string b) {
    ll m, n, i, j;
    m = a.size();
    n = b.size();
    ll ans = 0;
    fu(i, 1, n) {
        dp[0][i] = 0;
    }
    fu(i, 1, m) {
        dp[0][i] = 0;
    }
    fu(i, 1, m) {
        fu(j, 1, n) {
            if (a[i - 1] == b[j - 1]) {
                dir[i][j] = 'd';
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dir[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? 'u' : 'l';
            }
        }
    }
    ans = m - dp[m][n];
    pl(ans);
    pn();
    //print_lcs(a,m,n);
}

int main() {
    ll n;
    string s;
    sl(n);
    cin >> s;
    string rs = s;
    reverse(all(rs));
    lcs(s, rs);
    return 0;
}