#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
struct Edge {
    int to, c, f;
    Edge *rev;
    Edge(int to, int c) : to(to), c(c), f(0), rev(nullptr) {}
    int spare() {
        return c - f;
    }
    void addFlow(int ff) {
        f += ff;
        rev->f -= ff;
    }
};
vector<Edge *> g[808];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int u = i * 2;
        int v = i * 2 + 1;
        Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[u].push_back(e1);
        g[v].push_back(e2);
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u *= 2;
        v *= 2;
        Edge *e1 = new Edge(v, 1), *e2 = new Edge(u + 1, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[u+1].push_back(e1);
        g[v].push_back(e2);

        e1 = new Edge(u, 1), e2 = new Edge(v + 1, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[v + 1].push_back(e1);
        g[u].push_back(e2);
        
    }
    int ans = 0;
    int start = 3; int end = 4;
    while(true) {
        vector<int> pre(n * 2 + 2, -1);
        vector<Edge *> path(n * 2 + 2, nullptr);
        queue<int> q;
        q.push(start);
        while(!q.empty() && pre[end] == -1) {
            int now = q.front();
            q.pop();
            for(Edge *eg : g[now]) {
                int next = eg->to;
                if(eg->spare() > 0 && pre[next] == -1) {
                    pre[next] = now;
                    path[next] = eg;
                    q.push(next);
                    if(next == end) break;
                }
            }
        }

        if(pre[end] == -1) break;

        for(int i = end; i != start; i = pre[i]) {
            path[i]->addFlow(1);
        }
        ans += 1;
    }
    cout << ans << '\n';
    return 0;
}