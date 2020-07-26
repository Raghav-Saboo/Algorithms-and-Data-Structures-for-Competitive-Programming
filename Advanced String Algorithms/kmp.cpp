//Problem link https://www.hackerearth.com/practice/algorithms/string-algorithm/z-algorithm/practice-problems/algorithm/count-occurrences/
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
ll piarr[N];

void compute_prefix(string pat, ll m) {
    ll i, k, q;
    piarr[1] = 0;
    k = 0;
    fu(q, 2, m) {
        while (k > 0 && pat[k] != pat[q - 1]) {
            k = piarr[k];
        }
        if (pat[k] == pat[q - 1]) {
            k++;
        }
        piarr[q] = k;
    }
}

void kmp_matcher(string txt, string pat, ll n, ll m) {
    compute_prefix(pat, m);
    ll q, i, ans = 0;
    q = 0;
    fu(i, 1, n) {
        while (q > 0 && pat[q] != txt[i - 1]) {
            q = piarr[q];
        }
        if (pat[q] == txt[i - 1]) {
            q++;
        }
        if (q == m) {
            ans++;
            //pl(i-m);
            //ps();
            q = piarr[q];
        }
    }
    pl(ans);
    pn();
}

int main() {
    string txt, pat;
    cin >> pat >> txt;
    ll n, m;
    n = txt.size();
    m = pat.size();
    kmp_matcher(txt, pat, n, m);
    return 0;
}