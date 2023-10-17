#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int n;
struct asdf {
    double x, y;
};
double dist(asdf &a, asdf& b) {
    double t1 = (a.x - b.x) * (a.x - b.x);
    double t2 = (a.y - b.y) * (a.y - b.y);
    return sqrt(t1 + t2);
}
int p[100];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    p[x] = y;
}
int main() {
    fastio;
    cin >> n;
    vector<asdf> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    
    priority_queue<tuple<double, int, int>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            pq.push({-dist(a[i], a[j]), i, j});
        }
    }

    int cnt = 0;
    double ans = 0;
    memset(p,-1,sizeof(p));
    while(cnt < n - 1) {
        auto [d, x, y] = pq.top();
        pq.pop();
        d = -d;
        x = find(x);
        y = find(y);
        if(x != y) {
            set_union(x, y);
            cnt++;
            ans += d;
        }
    }
    cout << fixed << setprecision(2);
    cout << ans << '\n';
    return 0;
}