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
int start, num, s, r;
vector<Edge *> g[1001]; 
vector<pii> dg[1001];
bool hos[1001];
bool check[1001];
bool dfs(int now,int t) {
    if(t > s) return false;
    if(hos[now]) {
        return check[now] = true;
    }
    for(auto [next, dist] : dg[now]) {
        if(dfs(next, t + dist)) {
            check[now] = true;
        }
    }
    return check[now];
}
void init() {
    memset(hos,false,sizeof(hos));
    memset(check,false,sizeof(check));
    for(int i = 0; i < 1001; i++) {
        g[i].clear();
        dg[i].clear();
    }
}

int flow() {
    int total = 0;
    while(true) {
        vector<int> pre(n + 1, -1);
        vector<Edge *> path(n + 1, nullptr);
        queue<int> q;
        q.push(0);
        int end = - 1;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            for(Edge *eg : g[now]) {
                int next = eg->to;
                if(pre[next] == -1 && eg->spare() > 0 && check[next]) {
                    pre[next] = now;
                    path[next] = eg;
                    q.push(next);
                    if(hos[next]) {
                        end = next;
                        break;
                    }
                }
            }
            if(end != -1) break;
        }

        if(end == -1) break;

        int fl = 1e9;
        for(int i = end; i != 0; i = pre[i]) {
            fl = min(fl,path[i]->spare());
        }

        for(int i = end; i != 0; i = pre[i]) {
            path[i]->addFlow(fl);
        }
        total += fl;
    }
    return total;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n;
        cin >> start >> num >> s;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int tmp; cin >> tmp;
            hos[tmp] = true;
        }
        cin >> r;
        for(int i = 0; i < r; i++) {
            int t1, t2, t3, t4;
            cin >> t1 >> t2 >> t3 >> t4;
            Edge *e1 = new Edge(t2,t3 * t4), *e2 = new Edge(t1,0);
            e1->rev = e2;
            e2->rev = e1;
            g[t1].push_back(e1);
            g[t2].push_back(e2);
            dg[t1].push_back({t2, t4});
        }
        dfs(start, 0);
        Edge *e1 = new Edge(start, num), *e2 = new Edge(0,0);
        e1->rev = e2;
        e2->rev = e1;
        g[0].push_back(e1);
        g[start].push_back(e2);
        
        cout << flow() << '\n';
    }

    return 0;
}