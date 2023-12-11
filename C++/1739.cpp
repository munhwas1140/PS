#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k, SN;
vector<int> g[4040], gp[4040], order;
bool visited[4040];
int SCC[4040];
void init() {
    memset(SCC,0, sizeof(SCC));
    memset(visited,false,sizeof(visited));
    SN = 0;
    for(int i = 0; i < 4040; i++) {
        g[i].clear();
        gp[i].clear();
    }
}
int neg(int now) {
    return (now % 2 ? now - 1 : now + 1);
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
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if(a == c && b == d) continue;
            if(a == c) { // 
                int x = (a - 1) * 2;
                if(b > d) x++;
                g[neg(x)].push_back(x);
                g[neg(x)].push_back(x);
                gp[x].push_back(neg(x));
                gp[x].push_back(neg(x));
            } else if(b == d) {
                int x = 2 * n + (b - 1) * 2;
                if(a > c) x++;
                g[neg(x)].push_back(x);
                g[neg(x)].push_back(x);
                gp[x].push_back(neg(x));
                gp[x].push_back(neg(x));
            } else {
                int t1 = (c > a ? 0 : 1); // > down
                int t2 = (d > b ? 0 : 1); // > right
                // 왼쪽, 위, not
                int x = (a - 1) * 2 + t2;
                int y = 2 * n + (b - 1) * 2 + t1;
                int z = (c - 1) * 2 + t2;
                int h = 2 * n + (d - 1) * 2 + t1; 
                // x h, y z
                g[neg(x)].push_back(y);
                g[neg(y)].push_back(x);
                g[neg(y)].push_back(h);
                g[neg(h)].push_back(y);
                g[neg(x)].push_back(z);
                g[neg(z)].push_back(x);
                g[neg(h)].push_back(z);
                g[neg(z)].push_back(h);

                gp[y].push_back(neg(x));
                gp[x].push_back(neg(y));
                gp[h].push_back(neg(y));
                gp[y].push_back(neg(h));
                gp[z].push_back(neg(x));
                gp[x].push_back(neg(z));
                gp[z].push_back(neg(h));
                gp[h].push_back(neg(z));
            }
        }

        for(int i = 0; i < 2 * (n + m); i++) {
            if(!visited[i]) dfs(i);
        }
        memset(visited,false,sizeof(visited));
        reverse(order.begin(), order.end());
        
        for(int &i : order) {
            if(!SCC[i]) dfs_rev(i, ++SN);
        }
        
        bool ok = true;

        for(int i = 0; i < n + m; i++) {
            if(SCC[i * 2] == 0) continue;
            if(SCC[i * 2] == SCC[i * 2 + 1]) ok = false;
        }
        
        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}