#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int k, n;
struct Edge {
    int to, c, f;
    Edge *rev;
    Edge(int _to, int _c) : to(_to), c(_c), f(0), rev(nullptr) {};
    int spare() {
        return c - f;
    }
    void addFlow(int ff) {
        f += ff;
        rev->f -= ff;
    }
};
vector<Edge *> g[10001];
int flow() {
    int total = 0;

    while(true) {
        vector<int> pre(n * 2 + 2, -1);
        vector<Edge *> path(n * 2 + 2, nullptr);
        queue<int> q;
        q.push(3);
        while(!q.empty() && pre[4] == -1) {
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

        if(pre[4] == -1) break;
    
        int fl = 1e9;
        for(int i = 4; i != 3; i = pre[i]) {
            fl = min(fl, path[i]->spare());
        }
        for(int i = 4; i != 3; i = pre[i]) {
            path[i]->addFlow(fl);
        }
        total += fl;
    }
    return total;
}
void init() {
    for(int i = 0; i < 2 * n + 2; i++) {
        g[i].clear();
    }
}
void dfs(int now) {
    if(now == 4) {
        cout << now / 2 << '\n';
        return ;
    }
    if(now == 3) {
        int cnt = 0;
        for(int i = 0; cnt < k; i++) {
            Edge *eg = g[now][i];
            if(eg->c > 0 && eg->spare() == 0) {
                cnt++;
                if(now % 2) cout << now / 2 << ' ';
                dfs(eg->to);
            }
        }
    } else {
        for(Edge *eg : g[now]) {
            
            if(eg->c > 0 && eg->spare() == 0) {
                if(now % 2) cout << now / 2 << ' ';
                dfs(eg->to);
            }
        }
    }
}
int main() {
    fastio;
    for(int tc = 1;; tc++) {
        cin >> k >> n;
        if(k == 0 && n == 0) break;
        init();
        cin.ignore();
        string str;
        for(int i = 1; i <= n; i++) {
            Edge *e1 = new Edge(i * 2 + 1, 1), *e2 = new Edge(i * 2, 0);
            e1->rev = e2;
            e2->rev = e1;
            g[i * 2].push_back(e1);
            g[i * 2 + 1].push_back(e2);
            getline(cin, str);
            stringstream ss(str);
            int now = i * 2 + 1, tmp;
            while(ss >> tmp) {
                Edge *e1 = new Edge(tmp * 2, 1), *e2 = new Edge(now, 0);
                e1->rev = e2;
                e2->rev = e1;
                g[now].push_back(e1);
                g[tmp * 2].push_back(e2);
            }
        }

        int total = flow();
        cout << "Case " << tc << ":\n";
        if(total < k) {
            cout << "Impossible" << '\n';
        } else {
            dfs(3);
        }
        cout << '\n';
    }
    return 0;
}