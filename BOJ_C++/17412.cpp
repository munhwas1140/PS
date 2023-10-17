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
    Edge(int _to, int _c) : to(_to), c(_c), f(0), rev(nullptr) {}
    int spare() {
        return c - f;
    }
    void addFlow(int t) {
        f += t;
        rev->f -= t;
    }
};
vector<Edge *> g[401];
int main() {
    fastio;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        Edge *e1 = new Edge(t2, 1);
        Edge *e2 = new Edge(t1, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[t1].push_back(e1);
        g[t2].push_back(e2);
    }

    int s = 1, e = 2;
    int total = 0;
    while(true) {
        vector<int> pre(n + 1, -1);
        vector<Edge *> path(n + 1, nullptr);
        queue<int> q;
        q.push(s);
        while(!q.empty() && pre[e] == -1) {
            int now = q.front();
            q.pop();
            
            for(auto *eg : g[now]) {
                int next = eg->to;
                if(eg->spare() > 0 && pre[next] == -1) {
                    pre[next] = now;
                    path[next] = eg;
                    q.push(next);
                    if(next == e) break;
                }
            }
        }

        if(pre[e] == -1) break;
        
        for(int i = e; i != s; i = pre[i]) {
            path[i]->addFlow(1);
        }
        total += 1;
    }
    cout << total << '\n';
    return 0;
}