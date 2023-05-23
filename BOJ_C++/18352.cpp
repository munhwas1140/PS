#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<vector<int>> g(n + 1, vector<int>());
    
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
    }

    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[x] = 0;
    q.push(x);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(int next : g[now]) {
            if(dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }

    bool f = false;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == k) {
            f = true;
            cout << i << '\n';
        }
    }

    if(!f) cout << -1 << '\n';
    return 0;
}