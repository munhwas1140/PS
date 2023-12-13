#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MX = 1e18;
vector<pair<int, ll>> g[200001];
ll pdist[100001][2];
ll dist[200001];
int n, m;

void dijk(int s, int e, int TC, int k) {
    for(int i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    priority_queue<pll> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop(); d = -d;
        if(d > dist[now]) continue;

        for(auto &[next, cost] : g[now]) {
            if(dist[next] == -1 || dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                if(dist[next] > MX) dist[next] = MX + 1;
                pq.push({-dist[next], next});
            }
        }
    }

    pdist[TC][k] = dist[e];
}
void solve(int TC) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
    }

    for(int i = 0; i < m; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        if(x < 0) {
            if(pdist[-x][0] != -1) g[s].push_back({e, pdist[-x][0]});
            if(pdist[-x][1] != -1) g[e].push_back({s, pdist[-x][1]});
        } else {
            g[s].push_back({e, x});
        }
    }

    dijk(1, 2, TC, 0);
    dijk(2, 1, TC, 1);
}

int main() {
    fastio;
    int tc; cin >> tc;
    for(int TC = 1; TC <= tc; TC++) {
        solve(TC);
    }
    ll ans = pdist[tc][0];
    if(ans == MX + 1 || ans == -1) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}