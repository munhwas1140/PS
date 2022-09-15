#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, k, m;
vector<int> g[101001];
int dist[101001];
int main() {
    fastio;
    cin >> n >> k >> m;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            int tmp; cin >> tmp;
            g[tmp].push_back(n + i + 1);
            g[n + i + 1].push_back(tmp);
        }
    } 
    for(int i = 1; i <= n + m; i++) dist[i] = 1e9;
    dist[1] = 1;
    queue<pii> q;
    q.push({1, -1});

    while(!q.empty()) {
        auto [now, pre] = q.front();
        q.pop();

        for(int &next : g[now]) {
            if(dist[next] != 1e9) continue;
            if(next > n) {
                dist[next] = dist[now];
                q.push({next, now});
            } else {
                if(next != pre) {
                    dist[next] = dist[now] + 1;
                    q.push({next, now});
                }
            }
        }
    }

    if(dist[n] == 1e9) cout << -1 << '\n';
    else cout << dist[n] << '\n';
    return 0;
}