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
ll arr[N];
ll rear = -1, front = -1;

void enqueue(ll x) {
    if (front == -1) {
        front++;
        rear++;
    } else {
        rear++;
    }
    arr[rear] = x;
    cout << rear + 1 << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "-1 0\n";
    } else if (front == rear) {
        cout << arr[front] << " 0\n";
        front = rear = -1;
    } else {
        front++;
    }
}

int main() {
    ll n, x;
    char ch;
    sl(n);
    while (n--) {
        cin >> ch;
        if (ch == 'E') {
            sl(x);
            enqueue(x);
        } else {
            dequeue();
        }
    }
    return 0;
}