#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, s, e;
vector<pll> g[200001];
vector<int> p[200001];
ll dist[200001];
int main() {
    fastio;
    cin >> n >> m >> s >> e;

    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e16;
    }

    dist[s] = 0;
    priority_queue<pll> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();

        d = -d;
        if(dist[now] < d) continue;
        for(auto [next, cost] : g[now]) {
            if(dist[next] > d + cost) {
                p[next].clear();
                p[next].push_back(now);
                dist[next] = d + cost;
                pq.push({-dist[next], next});
            } else if(dist[next] == d + cost) {
                p[next].push_back(now);
            }
        }
    }

    vector<int> ans;
    queue<int> q;
    q.push(e);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(int next : p[now]) {
            q.push(next);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << (int)ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}