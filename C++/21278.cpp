#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> g[101];

int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    int ans_node1, ans_node2;
    int ans_dist = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> dist(n + 1, 1e9);
            dist[i] = 0;
            dist[j] = 0;

            priority_queue<pair<int, int>> pq;

            pq.emplace(0, i);
            pq.emplace(0, j);

            while (!pq.empty()) {
                auto [d, now] = pq.top();
                pq.pop();
                d *= -1;

                for (int next : g[now]) {
                    if (dist[next] > d + 1) {
                        dist[next] = d + 1;
                        pq.emplace(-dist[next], next);
                    }
                }
            }

            int tmp = 0;
            for (int k = 1; k <= n; k++) {
                tmp += dist[k] * 2;
            }

            if (ans_dist > tmp) {
                ans_node1 = i;
                ans_node2 = j;
                ans_dist = tmp;
            }
        }
    }
    cout << ans_node1 << ' ' << ans_node2 << ' ' << ans_dist << '\n';

    return 0;
}