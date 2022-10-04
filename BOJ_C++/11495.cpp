#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int a[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
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
vector<Edge *> g[2550];
void init() {
    memset(a,0,sizeof(a));
    for(int i = 0; i < 2550; i++) {
        g[i].clear();
    }
}
int flow() {
    // s == 0, e == n * m + 1;
    int total = 0;
    while(true) {
        vector<int> pre(n * m + 2, -1);
        vector<Edge *> path(n * m + 2, nullptr);
        queue<int> q;
        q.push(0);
        while(!q.empty() && pre[n * m + 1] == -1) {
            int now = q.front();
            q.pop();
            for(Edge *eg : g[now]) {
                int next = eg->to;
                if(eg->spare() > 0 && pre[next] == -1) {
                    pre[next] = now;
                    path[next] = eg;
                    q.push(next);
                }
            }
        }

        if(pre[n * m + 1] == -1) break;

        int fl = 1e9;
        for(int i = n * m + 1; i != 0; i = pre[i]) {
            fl = min(fl, path[i]->spare());
        }
        for(int i = n * m + 1; i != 0; i = pre[i]) {
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
        cin >> n >> m;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                sum += a[i][j];
            }
        }


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int now = m * i + j;
                if((j + i) % 2 == 0) {
                    Edge *e1 = new Edge(now + 1, a[i][j]), *e2 = new Edge(0, 0);
                    e1->rev = e2;
                    e2->rev = e1;
                    g[0].push_back(e1);
                    g[now + 1].push_back(e2);
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        int next = nx * m + ny;
                        Edge *e1 = new Edge(next + 1, 1e9), *e2 = new Edge(now + 1, 0);
                        e1->rev = e2;
                        e2->rev =e1;
                        g[now + 1].push_back(e1);
                        g[next + 1].push_back(e2);
                    }
                } else {
                    Edge *e1 = new Edge(n * m + 1, a[i][j]), *e2 = new Edge(now + 1, 0);
                    e1->rev = e2;
                    e2->rev = e1;
                    g[now + 1].push_back(e1);
                    g[n * m + 1].push_back(e2);
                }
            }
        }

        int tmp = flow();
        cout << sum - tmp << '\n';
    }    

    return 0;
}