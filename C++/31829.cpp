#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, t1, t2;
ll k;
vector<pair<int,ll>> g1[200001];
vector<pair<int,ll>> g2[200001];
ll dist[200001];
int main() {
    fastio;
    cin >> n >> k >> t1 >> t2;

    for(int i = 1; i <= n; i++) dist[i] = 1e18;

    for(int i = 0; i < t1; i++) {
        int s, e;
        ll x;
        cin >> s >> e >> x;
        g1[s].emplace_back(e, x);
        g1[e].emplace_back(s, x);
    }

    for(int i = 0; i < t2; i++) {
        int s, e;
        ll x;
        cin >> s >> e >> x;
        g2[s].emplace_back(e, x);
        g2[e].emplace_back(s, x);
    }

    dist[1] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, 1);
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d *= -1;
        if(d > dist[now]) continue;

        for(auto [next, cost] : g1[now]) {
            if(dist[next] > d + cost) {
                dist[next] = d + cost;
                pq.emplace(-dist[next], next);
            }
        }

        for(auto [next, cost] : g2[now]) {
            ll alpha = max(0LL, k - d);
            if(dist[next] > d + cost + alpha) {
                dist[next] = d + cost + alpha;
                pq.emplace(-dist[next], next);
            }
        }
    }

    cout << dist[n] << '\n';
    return 0;
}
