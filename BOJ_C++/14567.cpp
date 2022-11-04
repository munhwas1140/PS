#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<int> g[1001];
int ind[1001];
int dist[1001];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        ind[t2]++;
    }
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            q.push(i);
            dist[i] = 1;
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int next : g[now]) {
            ind[next]--;
            if(ind[next] == 0) {
                if(dist[next] == -1 || dist[next] < dist[now] + 1) {
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }

    return 0;
}