#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
vector<pii> g[50505];
vector<pii> pos;
vector<int> dijk(int s) {
    vector<int> dist(n + 2, 1e9);

    dist[s] = 0;
    priority_queue<pii> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        
        d = -d;
        if(dist[now] < d) continue;
        for(auto [next, cost] : g[now]) {
            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                pq.push({-dist[next], next});
            }
        }
    }
    return dist;
}
int main() {
    fastio;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        g[s].push_back({e, t});
        g[e].push_back({s, t});
    }

    for(int i = 0; i < k; i++) {
        int x, h;
        cin >> x >> h;
        pos.push_back({x, h});
    }

    vector<int> dist = dijk(n);

    for(auto [x, cost] : pos) {
        g[n + 1].push_back({x, dist[x] - cost});
    }
    vector<int> dist2 = dijk(n + 1);

    for(int i = 1; i < n; i++) {
        cout << (dist[i] >= dist2[i]) << '\n';
    }

    return 0;
}