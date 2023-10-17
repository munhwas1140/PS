#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

struct asdf {
    int x, y, z, idx;
};
int p[100000];
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
int n;
int main() {
    fastio;
    cin >> n;
    vector<asdf> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].idx = i;
    }
    priority_queue<tuple<ll, int, int>> pq;
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.x < b.x;
    });
    for(int i = 0; i < n - 1; i++) {
        pq.push({-abs(a[i].x - a[i+1].x), a[i].idx, a[i+1].idx});
    }

    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.y < b.y;
    });
    for(int i = 0; i < n - 1; i++) {
        pq.push({-abs(a[i].y - a[i+1].y), a[i].idx, a[i+1].idx});
    }

    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.z < b.z;
    });
    for(int i = 0; i < n - 1; i ++) {
        pq.push({-abs(a[i].z - a[i+1].z), a[i].idx, a[i+1].idx});
    }

    int cnt = 0;
    ll ans = 0;
    memset(p,-1,sizeof(p));
    while(cnt < n - 1) {
        auto [d, x, y] = pq.top();
        pq.pop();
        d = -d;
        x = find(x);
        y = find(y);
        if(x != y) {
            cnt++;
            ans += d;
            set_union(x, y);
        }
    }
    cout << ans << '\n';
    return 0;
}