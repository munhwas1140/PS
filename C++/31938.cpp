#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pair<int,ull>> g[200001];
ll dist[200001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int s, e;
        ull x;
        cin >> s >> e >> x;
        g[s].push_back({e, x});
        g[e].push_back({s, x});
    }
    for(int i = 1; i <= n; i++) {
        dist[i] = ULLONG_MAX;
    }

    // dist, reamin, v
    priority_queue<tuple<ull, ull, int>> pq;
    pq.push({0LL, ll(n), 1});

    while(!pq.empty()) {
        auto [d, remain, now] = pq.top();
        pq.pop();

        d *= -1;
        if(dist[now] < d) continue;
        for(auto [next, d] : g[now]) {


        }
    }


    ull ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dist[i];
    }

    cout << ans << '\n';

    return 0;
}





