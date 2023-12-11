#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
ll dcache[100001], dist[200001];
vector<pll> g[200001];
void solve(int tc) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        g[n].clear();
        dist[i] = 1e18;
    }
    for(int i = 0; i < m; i++) {
        int s, e;
        ll x;
        cin >> s >> e >> x;
        if(x < 0) x = dcache[-x];
        g[s].push_back({e, x});
    }

    priority_queue<pll> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d = -d;
        if(dist[now] < d) continue;
        
        for(auto &[next, cost] : g[now]) {
            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                pq.push({-dist[next], next});
            }
        }
    }
    dcache[tc] = dist[2];
}

int main() {
    fastio;
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++) {
        solve(i);
        cout << dcache[i] << '\n';

    }
    return 0;
}