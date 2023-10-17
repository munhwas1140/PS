#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n, m;
vector<pii> g[1001];
int dist[1001];
int pre[1001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2, t3});
        g[t2].push_back({t1, t3});
    }
    
    for(int i = 1; i <= n; i++) dist[i] = 1e9;

    dist[1] = 0;
    priority_queue<pii> pq;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        auto [d, now] = pq.top();
        pq.pop();
        d = -d; 
        for(auto &next : g[now]) {
            if(dist[next.first] > d + next.second) {
                dist[next.first] = d + next.second;
                pre[next.first] = now;
                pq.push({-dist[next.first], next.first});
            }
        }
    } 
    vector<int> pos;
    for(int i = 2; i <= n; i++) {
        if(dist[i] != 1e9) {
            pos.push_back(i);
        }
    }
    cout << pos.size() << '\n';
    for(auto &v : pos) {
        cout << v << ' ' << pre[v] << '\n';
    }
 
    return 0;
}