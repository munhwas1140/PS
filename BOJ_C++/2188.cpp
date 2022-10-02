#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, pre[444];
struct edge {
    int to, c, f;
    edge *rev;
    edge(int to, int c) : to(to), c(c), f(0) {}
    int spare() {
        return c - f;
    }
    void addFlow(int f1) {
        f += f1;
        rev->f += f1;
    }
};
vector<edge *> g[444];
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int x; cin >> x;
            edge *e1 = new edge(n + x, 1), *e2 = new edge(i, 0);
            e1->rev = e2;
            e2->rev = e1;
            g[i].push_back(e1);
            g[x].push_back(e2);
        }
    }

    for(int i = 1; i <= n; i++) {
        edge *e1 = new edge(i, 1), *e2 = new edge(0, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[0].push_back(e1);
        g[i].push_back(e2);
    }

    for(int i = n + 1; i <= n + m; i++) {
        edge *e1 = new edge(n + m + 1, 1), *e2 = new edge(i, 0);
        e1->rev = e2;
        e2->rev = e1;
        g[i].push_back(e1);
        g[n + m + 1].push_back(e2);
    }

    int start = 0, end = n + m + 1;
    int total = 0;
    while(1) {
        vector<edge *> path(n + m + 2, nullptr);
        memset(pre,-1,sizeof(pre));
        queue<int> q;
        q.push(start);
        
        while(!q.empty() && pre[end] == -1) {
            int now = q.front();
            q.pop();
            
            for(auto *eg : g[now]) {
                int next = eg->to;
                if(eg->spare() > 0 && pre[next] == -1) {
                    q.push(next);
                    pre[next] = now;
                    path[next] = eg;
                    if(next == end) break;
                }
            }
        }

        if(pre[end] == -1) break;
        
        int flow = 1e9;
        for(int i = end; i != start; i = pre[i]) {
            flow = min(flow, path[i]->spare());
        }
        for(int i = end; i != start; i = pre[i]) {
            path[i]->addFlow(flow);
        }
        total += flow;
    }
    cout << total << '\n';
    return 0;
}