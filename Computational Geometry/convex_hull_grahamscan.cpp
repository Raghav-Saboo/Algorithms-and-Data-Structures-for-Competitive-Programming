//Problem Link http://www.spoj.com/problems/BSHEEP/
#include <bits/stdc++.h>

using namespace std;
struct point {
    long long int x;
    long long int y;
};
map<pair<long long int, long long int>, long long int> mp;
struct point arr[100005];
stack<struct point> s;
vector<struct point> v;
struct point P0;

double dis(struct point a, struct point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int ck_ack_cl(struct point p0, struct point p1, struct point p2) {
    long long int v;
    v = (p2.x - p0.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p0.y);
    if (v == 0) {
        return 0;
    } else if (v < 0) {
        return -1;
    } else {
        return 1;
    }
}

int cmp(const void *a, const void *b) {
    struct point p1 = *((struct point *) a);
    struct point p2 = *((struct point *) b);
    int v = ck_ack_cl(P0, p1, p2);
    if (v == 0) {
        if (dis(P0, p1) < dis(P0, p2)) {
            return -1;
        } else {
            return 1;
        }
    } else {
        return v;
    }
}

int main() {
    long long int n, t;
    long long int i, x, y, mny, mnx, p;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        mny = -10005;
        mnx = -10005;
        for (i = 0; i < n; i++) {
            scanf("%lld%lld", &x, &y);
            arr[i].x = x;
            arr[i].y = y;
            if (mp.find(make_pair(x, y)) == mp.end()) {
                mp[make_pair(x, y)] = i + 1;
            }
            if (i == 0) {
                p = i;
                mny = y;
                mnx = x;
            } else if (y < mny) {
                p = i;
                mny = y;
                mnx = x;
            } else if (y == mny && x < mnx) {
                p = i;
                mnx = x;
            }
        }
        struct point tmp;
        tmp = arr[0];
        arr[0] = arr[p];
        arr[p] = tmp;
        P0 = arr[0];
        qsort(arr + 1, n - 1, sizeof(struct point), cmp);
        long long int m = 1;
        for (i = 1; i < n; i++) {
            while (i < n - 1 && ck_ack_cl(P0, arr[i], arr[i + 1]) == 0) {
                i++;
            }
            arr[m] = arr[i];
            m++;
        }
        if (m < 3) {
            double ans = 0;
            for (i = 0; i < m; i++) {
                v.push_back(arr[i]);
            }
            for (i = 0; i < v.size(); i++) {
                if (i != v.size() - 1) {
                    ans += dis(v[i], v[i + 1]);
                }
            }
            ans *= 2;
            printf("%.2lf\n", ans);
            for (i = 0; i < v.size(); i++) {
                printf("%lld ", mp[make_pair(v[i].x, v[i].y)]);
            }
            printf("\n");
        } else {
            s.push(arr[0]);
            s.push(arr[1]);
            s.push(arr[2]);
            for (i = 3; i < m; i++) {
                struct point u, v, w;
                v = s.top();
                s.pop();
                u = s.top();
                s.push(v);
                w = arr[i];
                while (ck_ack_cl(u, v, w) != -1) {
                    s.pop();
                    v = s.top();
                    s.pop();
                    u = s.top();
                    s.push(v);
                    w = arr[i];
                    //s.pop();
                }
                s.push(arr[i]);
            }
            double ans = 0;
            while (!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
            reverse(v.begin(), v.end());
            for (i = 0; i < v.size(); i++) {
                if (i != v.size() - 1) {
                    ans += dis(v[i], v[i + 1]);
                }
            }
            ans += dis(v[0], v[v.size() - 1]);
            printf("%.2lf\n", ans);
            for (i = 0; i < v.size(); i++) {
                printf("%lld ", mp[make_pair(v[i].x, v[i].y)]);
            }
            printf("\n");
        }
        mp.clear();
        v.clear();
        while (!s.empty()) {
            s.pop();
        }
        printf("\n");
    }
    return 0;
} 