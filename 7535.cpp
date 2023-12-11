#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int n, m;
vector<int> g[2001];
int check[2001];
void init() {
    for(int i = 0; i < 2001; i++) {
        g[i].clear();
    }
    memset(check,-1,sizeof(check));
}
bool ok;
void dfs(int now, int gen) {
    check[now] = gen;
    
    for(int &next : g[now]) {
        if(check[next] == -1) {
            dfs(next, 1 - gen);
        } else {
            if(check[next] == check[now]) {
                ok = false;
                return ;
            }
        }
    }
}
int main() {
    fastio;
    int tt; cin >> tt;
    for(int tc = 1; tc <= tt; tc++) {
        init();
        ok = true;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
        }
        // 0 = male, 1 = female;
        for(int i = 1; i <= n; i++) {
            if(ok && check[i] == -1) dfs(i, 0);
        }
        cout << "Scenario #" << tc << ":\n";
        if(ok) cout << "No suspicious bugs found!\n\n";
        else cout << "Suspicious bugs found!\n\n";
    }

    return 0;
}