#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct Edge {
    int to, c, f;
    Edge *rev;
    Edge(int _to, int _c) : to(_to), c(_c), f(0), rev(nullptr) {}
    int spare() {
        return c - f;
    }
    void addFlow(int ff) {
        f += ff;
        rev->f -= ff;
    }
};
int n, m;
vector<Edge *> g[1111];
int flow() {
    int total = 0;
    while(true) {
        vector<int> pre(n + m + 2, -1);
        vector<Edge *> path(n + m + 2, nullptr);
        queue<int> q;
        q.push(0);
        while(!q.empty() && pre[n + m + 1] == -1) {
            int now = q.front();
            q.pop();
            for(Edge *eg : g[now]) {
                int next = eg->to;
                if(pre[next] == -1 && eg->spare() > 0) {
                    pre[next] = now;
                    path[next] = eg;
                    q.push(next);
                }
            }
        }

        if(pre[n + m + 1] == -1) break;

        int fl = 1e9;
        for(int i = n + m + 1; i != 0; i = pre[i]) {
            fl = min(fl, path[i]->spare());
        }

        for(int i = n + m + 1; i != 0; i = pre[i]) {
            path[i]->addFlow(fl);
        }
        total += fl;
    }
    return total;
}
int main() {
    fastio;
    cin >> m >> n;
    for(int i = n + 1; i <= n + m; i++) {
        int tmp; cin >> tmp;
        Edge *e1 = new Edge(n + m + 1, tmp), *e2 = new Edge(i, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[i].push_back(e1);
        g[n + m + 1].push_back(e2);
    }

    vector<int> key[1001];
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int tt; cin >> tt;
            key[tt].push_back(i);
            Edge *e1 = new Edge(n + tt, 1e9), *e2 = new Edge(i, 0);
            e1->rev = e2;
            e2->rev = e1;
            g[i].push_back(e1);
            g[n + tt].push_back(e2);
        }
        int k; cin >> k;
        Edge *e1 = new Edge(i, k), *e2 = new Edge(0, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[0].push_back(e1);
        g[i].push_back(e2);
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < key[i].size(); j++) {
            for(int k = j + 1; k < key[i].size(); k++) {
                int s = key[i][k], e = key[i][j];
                Edge *e1 = new Edge(e, 1e9), *e2 = new Edge(s, 0);
                e1->rev = e2;
                e2->rev = e1;
                g[s].push_back(e1);
                g[e].push_back(e2);
            }
        }
    }

    cout << flow() << '\n';
    return 0;
}