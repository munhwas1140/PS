#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int c[301][301], f[301][301];
vector<int> g[301];
vector<pii> edge;
int n, m;

void init() {
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    for(int i = 0; i < 301; i++) {
        g[i].clear();
    }
    edge.clear();
}
void flow() {
    while(true) {
        vector<int> pre(n + 1, -1);
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int &next : g[now]) {
                if(pre[next] == -1 && c[now][next] - f[now][next] > 0) {
                    pre[next] = now;
                    q.push(next);
                }
            }
        }
        
        if(pre[n] == -1) break;
        
        int fl = 1e9;
        for(int i = n; i != 1; i = pre[i]) {
            fl = min(fl, c[pre[i]][i] - f[pre[i]][i]);
        }
        for(int i = n; i != 1; i = pre[i]) {
            f[pre[i]][i] += fl;
            f[i][pre[i]] -= fl;
        }
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
            c[t1][t2] += t3;
            edge.push_back({t1, t2});
        }
        flow();
        int ans = 0;
        for(auto [x, y] : edge) {
            if(c[x][y] == 0 || c[x][y] > f[x][y]) continue;
            vector<int> pre(n + 1, -1);
            queue<int> q;
            q.push(x);
            while(!q.empty()) {
                int now = q.front();
                q.pop();
                for(int &next : g[now]) {
                    if(pre[next] == -1 && c[now][next] - f[now][next] > 0) {
                        pre[next] = now;
                        q.push(next);
                    }
                }
            }
            if(pre[y] == -1) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}