#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, m;
vector<int> g[20000];
vector<int> gp[20000];
vector<int> order;
int SCCcnt;
int SCC[20000];
bool visited[20000];
int oppo(int n) {
    return ( n % 2 ? n - 1 : n + 1);
}
void dfs(int now) {
    visited[now] = true;
    for(int &next : g[now]) {
        if(!visited[next]) dfs(next);
    }
    order.push_back(now);
}
void dfs_rev(int now, int num) {
    visited[now] = true;
    SCC[now] = num;
    for(int &next : gp[now]) {
        if(!visited[next]) dfs_rev(next, num);
    }
}
int main() {
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a = (a < 0 ? -(a + 1) * 2 : a * 2 - 1);
        b = (b < 0 ? -(b + 1) * 2 : b * 2 - 1);
        int na = oppo(a);
        int nb = oppo(b);
        g[na].push_back(b);
        g[nb].push_back(a);
        gp[b].push_back(na);
        gp[a].push_back(nb);
    }

    for(int i = 0; i < 2 * n; i++) {
        if(!visited[i]) dfs(i);
    }

    memset(visited,false,sizeof(visited));
    reverse(order.begin(), order.end());
    
    for(int &i : order) {
        if(!SCC[i]) dfs_rev(i, ++SCCcnt);
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(SCC[i * 2] == SCC[i * 2 + 1]) {
            ok = false;
            break;
        }
    }
    
    if(ok) {
        int res[10000];
        memset(res,-1,sizeof(res));
        vector<pii> p(2 * n);
        for(int i = 0; i < 2 * n; i++) {
            p[i] = make_pair(SCC[i], i);
        }
        sort(p.begin(), p.end());
        for(int i = 0; i < 2 * n; i++) {
            int now = p[i].second;
            if(res[now / 2] == -1) {
                res[now / 2] = !(now % 2);
            }
        }
        cout << 1 << '\n';
        for(int i = 0; i < n; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}