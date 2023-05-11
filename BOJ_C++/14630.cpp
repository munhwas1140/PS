#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<pii> g[1001];
int dist[1001];
int sz;
int check(string &a, string &b) {
    int ret = 0;
    for(int i = 0; i < sz; i++) {
        ret += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sz = a[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cost = check(a[i], a[j]);
            g[i].push_back({j, cost});
            g[j].push_back({i, cost});
        }
    }

    int s, e;
    cin >> s >> e;
    s--; e--;

    for(int i = 0; i < 1001; i++) {
        dist[i] = 1e9;
    }

    dist[s] = 0;    
    priority_queue<pii> q;
    q.push({0, s});
    while(!q.empty()) {
        auto [d, now] = q.top();
        q.pop();
        d = -d;
        if(d > dist[now]) continue;
        for(auto &[next, cost] : g[now]) {
            if(dist[next] > dist[now] + cost) {
                dist[next] = dist[now] + cost;
                q.push({-dist[next], next});
            }
        }
    }
    cout << dist[e] << '\n';
    return 0;
}