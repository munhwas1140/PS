#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int n, m;
vector<pii> g[801];
int dist[801][4];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) {
            dist[i][j] = 1e9;
        }
    }

    int t1, t2;
    cin >> t1 >> t2;

    priority_queue<tuple<int, int, int>> pq;
    int start;
    if(t1 == 1) start = 1;
    else if(t2 == 1) start = 2;
    else start = 0;
    dist[1][start] = 0;
    pq.push({0, 1, start});

    while(!pq.empty()) {
        auto [d, now, state] = pq.top();
        pq.pop();
        d = -d;
        if(dist[now][state] < d) continue;
        for(auto &next : g[now]) {
            int tmp = state;
            if(next.first == t1) tmp |= 1;
            else if(next.first == t2) tmp |= 2;
            if(dist[next.first][tmp] > d + next.second) {
                dist[next.first][tmp] = d + next.second;
                pq.push({-dist[next.first][tmp], next.first, tmp});
            }
        }
    }

    if(dist[n][3] == 1e9) cout << -1 << '\n';
    else cout << dist[n][3] << '\n';
    return 0;
}