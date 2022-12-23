#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[3000];
struct Line {
    pii p1, p2;
};
vector<Line> a;
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[y] += p[x];
        p[x] = y;
    }
}
int ccw(pii &t1, pii &t2, pii &t3) {
    int op = t1.first * t2.second + t2.first * t3.second + t3.first * t1.second;
    op -= t1.second * t2.first + t2.second * t3.first + t3.second * t1.first;
    if(op > 0) return 1;
    else if(op < 0) return -1;
    return 0;
}
bool connect(int x, int y) {
    Line l1 = a[x];
    Line l2 = a[y];
    int ab = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int cd = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
    if(ab == 0 && cd == 0) {
        if(l1.p1 > l1.p2) swap(l1.p1, l1.p2);
        if(l2.p1 > l2.p2) swap(l2.p1, l2.p2);
        return l2.p1 <= l1.p2 && l1.p1 <= l2.p2;
    }
    return ab <= 0 && cd <= 0;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));

    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].p1.first >> a[i].p1.second >> a[i].p2.first >> a[i].p2.second;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(connect(i, j)) {
                set_union(i, j);
            }
        }
    }

    int cnt = 0;
    int mv = -1;
    for(int i = 0; i < n; i++) {
        if(find(i) == i) cnt++;
        mv = max(mv, -p[find(i)]);
    }

    cout << cnt << '\n' << mv << '\n';

    return 0;
}