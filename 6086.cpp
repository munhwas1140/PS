#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct Edge {
    int to, c, f;
    Edge *rev;
    Edge() : Edge(-1, 0) {}
    Edge(int to1, int c1) : to(to1), c(c1), f(0), rev(nullptr) {}
    int spare() {
        return c - f;
    }
    void addFlow(int f1) {
        f += f1;
        rev->f -= f1;
    }
};
int n, pre[52];
vector<Edge *> g[52];
int ctoi(char now) {
    if(now <= 'Z') return now - 'A';
    return now - 'a' + 26;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u = ctoi(u);
        v = ctoi(v);
        Edge *e1 = new Edge(v, w), *e2 = new Edge(u, w);
        e1->rev = e2;
        e2->rev = e1;
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    
    int total = 0;
    int s = ctoi('A'), e = ctoi('Z');

    while(true) {
        memset(pre,-1,sizeof(pre));
        vector<Edge *> path(52, nullptr);
        queue<int> q;
        q.push(s);
        while(!q.empty() && pre[e] == -1) {
            int now = q.front();
            q.pop();
            for(Edge *eg : g[now]) {
                int next = eg->to;
                if(eg->spare() > 0 && pre[next] == -1) {
                    q.push(next);
                    pre[next] = now;
                    path[next] = eg;
                    if(next == e) break;
                }
            }
        }
        
        if(pre[e] == -1) break;

        int flow = 1e9;
        for(int i = e; i != s; i = pre[i]) {
            flow = min(flow, path[i]->spare());
        } 
        for(int i = e; i != s; i = pre[i]) {
            path[i]->addFlow(flow);
        }
        total += flow;
    }
    cout << total << '\n';
    return 0;
}