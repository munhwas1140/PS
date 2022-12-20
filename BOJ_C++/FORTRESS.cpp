#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct C {
    int x, y, r;
};
int n;
vector<int> g[101];
vector<C> a;
bool visited[101];
int dep[101];
int sqr(int x) {
    return x * x;
}
int sqrdist(int u, int v) {
    return sqr(a[u].x - a[v].x) + sqr(a[u].y - a[v].y);
}
bool encloses(int u, int v) {
    return a[u].r > a[v].r && (sqrdist(u, v) < sqr(a[u].r - a[v].r));

}
bool isChild(int p, int c) {
    if(!encloses(p, c)) return false;
    for(int i = 0; i < n; i++) {
        if(i != p && i != c && encloses(p, i) && encloses(i, c)) return false;
    }
    return true;
}
void makeg(int now) {
    for(int i = 0; i < n; i++) {
        if(i == now) continue;
        if(isChild(now, i)) {
            g[now].push_back(i);
            g[i].push_back(now);
            makeg(i);
        }
    }
}
void init() {
    a.clear();
    a.resize(n);
    memset(visited,false,sizeof(visited));
    memset(dep,0,sizeof(dep));
    for(int i = 0; i < 101; i++) {
        g[i].clear();
    }
}

int dfs(int now) {
    int ret = 1;
    visited[now] = true;
    for(int i = 0; i < g[now].size(); i++) {
        int next = g[now][i];
        if(!visited[next]) {
            dep[next] = dep[now] + 1;
            ret = max(ret, dfs(next));
        }
    }
    visited[now] = false;
    ret = max(ret, dep[now]);
    return ret;
}
void solve() {
    cin >> n;
    init();
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }

    if(n == 1) {
        cout << 0 << '\n';
        return ;
    }

    makeg(0);
    dep[0] = 0;
    int x = dfs(0);
    for(int i = 1; i < n; i++) {
        if(dep[i] == x) {
            dep[i] = 0;
            cout << dfs(i) << '\n';
            return ;

        }
    }
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}