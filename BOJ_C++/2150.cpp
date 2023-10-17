#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
// 코사라
int n, m;
vector<int> g[100001];
vector<int> gp[100001];
bool visited[100001];
int SCC[100001];
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
int main() {
    fastio;
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
    for(auto i : order) {
        if(!SCC[i]) dfs_rev(i, ++cnt);
    }

    cout << cnt << '\n';
    vector<vector<int>> ans(cnt);
    for(int i = 1; i <= n; i++) {
        ans[SCC[i] - 1].push_back(i);
    }
    for(int i = 0; i < cnt; i++) {
        sort(ans[i].begin(), ans[i].end());
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < cnt; i++) {
        for(int &x : ans[i]) {
            cout << x << ' ';
        }
        cout << -1 << '\n';
    }
    return 0;
}