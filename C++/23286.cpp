#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, t;
vector<pii> g[301];
int dist[301][301];
int main() {
    fastio;
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        g[s].push_back({e, x});
    }

    memset(dist,-1,sizeof(dist));

    for(int i = 1; i <= n; i++) {
        priority_queue<pii> pq;
        pq.push({0, i});
        dist[i][i] = 0;
        while(!pq.empty()) {
            auto [d, now] = pq.top();
            pq.pop();
            d = -d;
            for(auto [next, h] : g[now]) {
                if(dist[i][next] == -1 || dist[i][next] > max(d, h)) {
                    dist[i][next] = max(d, h);
                    pq.push({-max(d, h), next});
                }
            }
        }
    }

    while(t--) {
        int s, e;
        cin >> s >> e;
        int tmp = dist[s][e];
        if(tmp == 1e9) cout << -1 << '\n';
        else cout << tmp << '\n';
    }

    return 0;
}