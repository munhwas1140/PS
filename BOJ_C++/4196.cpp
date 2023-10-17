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
int indeg[100001];
vector<int> g[100001];
vector<int> gp[100001];
int SCC[100001];
bool visited[100001];
vector<int> order;
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
void init() {
    order.clear();
    for(int i = 1; i <= 100000; i++) {
        g[i].clear();
        gp[i].clear();
    }
    memset(indeg,0,sizeof(indeg));
    memset(SCC,0,sizeof(SCC));
    memset(visited,false,sizeof(visited));
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        init();
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            gp[t2].push_back(t1);
        }
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) dfs(i);
        }
        memset(visited,false,sizeof(visited));
        reverse(order.begin(), order.end());

        int cnt = 0;
        for(int &i : order) {
            if(!SCC[i]) dfs_rev(i, ++cnt);
        }

        for(int i = 1; i <= n; i++) {
            for(int &next : g[i]) {
                if(SCC[i] != SCC[next]) {
                    indeg[SCC[next]]++;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= cnt; i++) {
            if(indeg[i] == 0) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}