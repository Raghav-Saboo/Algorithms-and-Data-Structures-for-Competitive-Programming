//Problem link  https://www.hackerearth.com/problem/algorithm/q5-2/
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
#define N 1005
ll arr[N][N], s[N][N];

int main() {
    ll n, m, i, j, x1, x2, y1, y2, q, ans;
    sl(n);
    sl(m);
    sl(q);
    fu(i, 1, n) {
        fu(j, 1, m) {
            sl(arr[i][j]);
        }
    }
    s[1][1] = arr[1][1];
    fu(i, 2, n) {
        s[1][i] = s[1][i - 1] + arr[1][i];
    }
    fu(j, 2, m) {
        s[j][1] = s[j - 1][1] + arr[j][1];
    }
    fu(i, 2, n) {
        fu(j, 2, m) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] + arr[i][j] - s[i - 1][j - 1];
        }
    }
    while (q--) {
        sl(x1);
        sl(y1);
        sl(x2);
        sl(y2);
        if (x1 == 1 && y1 == 1) {
            ans = s[x2][y2];
        } else if (y1 > 1 && x1 == 1) {
            ans = s[x2][y2] - s[x2][y1 - 1];
        } else if (x1 > 1 && y1 == 1) {
            ans = s[x2][y2] - s[x1 - 1][y2];
        } else {
            ans = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        }
        pl(ans);
        pn();
    }
    return 0;
}
