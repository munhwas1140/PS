#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<pll> g[100001];
bool posb[100001];
vector<int> pos;
ll dist[100001];
void init(int n) {
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }
}

int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    init(n);

    for(int i = 0; i < m; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        g[e].emplace_back(s, d);
    }

    for(int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        pos.push_back(tmp);
        posb[tmp] = true;
    }

    priority_queue<pair<ll, int>> pq;
    for(const int &x : pos) {
        pq.emplace(0LL, x);
        dist[x] = 0;
    }

    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d *= -1LL;
        if(dist[now] < d) continue;
        for(const auto &next : g[now]) {
            if(d + next.second < dist[next.first]) {
                dist[next.first] = d + next.second;
                pq.emplace(-dist[next.first], next.first);
            }
        }
    }

    int idx = -1;
    for(int i = 1; i <= n; i++) {
        if(posb[i]) continue;
        if(idx == -1 || dist[idx] < dist[i]) {
            idx = i;
        }
    }
    cout << idx << '\n' << dist[idx] << '\n';
    return 0;
}