#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct P {
    int x, y, z, idx;
};
int dist[400002];
vector<pair<int, int>> g[400002];
int n, k;
int main() {
    fastio; 
    cin >> n >> k;
    vector<P> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        int x = a[i].z % k;
        int y = (k - x) % k;
        g[i].push_back({n + x, a[i].z});
        g[n + y].push_back({i, a[i].z});
        a[i].idx = i;
    }

    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.x < b.x;
    });
    for(int i = 0; i < n - 1; i++) {
        int diff = a[i + 1].x - a[i].x;
        g[a[i].idx].push_back({a[i + 1].idx, diff});
        g[a[i + 1].idx].push_back({a[i].idx, diff});
    }

    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.y < b.y;
    });
    for(int i = 0; i < n - 1; i ++) {
        int diff =a[i + 1].y - a[i].y;
        g[a[i].idx].push_back({a[i + 1].idx, diff});
        g[a[i + 1].idx].push_back({a[i].idx, diff});
    }


    


    for(int i = 0; i < n + k + 1; i++) {
        dist[i] = 1e9 + 7;
    }
    dist[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d = -d;
        if(d > dist[now]) continue;
        for(auto &next : g[now]) {
            if(dist[next.first] > d + next.second) {
                dist[next.first] = d + next.second;
                pq.push({-dist[next.first], next.first});
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << dist[i] << '\n';
    }
    return 0;
}