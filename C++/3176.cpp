#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100001];
int depth[100001];
bool visited[100001];
int dp[100001][30];
pair<int, int> dist[100001][30];
int n;

void DFS(int now, int d) {
    visited[now] = true;
    depth[now] = d;
    for(auto next : g[now]) {
        if(!visited[next.first]) {
            dp[next.first][0] = now;
            dist[next.first][0] = make_pair(next.second, next.second);
            DFS(next.first, d + 1);
        }
    }
}

void dpSet() {
    for(int j = 1; j < 30; j++) {
        for(int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
            dist[i][j].first = min(dist[i][j-1].first, dist[dp[i][j-1]][j-1].first);
            dist[i][j].second = max(dist[i][j-1].second, dist[dp[i][j-1]][j-1].second);
        }
    }
}

void compare(pair<int,int> &ans ,pair<int,int> &p) {
    ans.first = min(ans.first, p.first);
    ans.second = max(ans.second, p.second);
}

pair<int,int> LCA(int t1, int t2) {
    if(depth[t1] < depth[t2]) swap(t1, t2);
    pair<int,int> ans = make_pair(1e9, -1e9);
    int diff = depth[t1] - depth[t2];

    for(int i = 0; i < 30; i++) {
        if(diff & 1) {
            compare(ans, dist[t1][i]);
            t1 = dp[t1][i];
        }
        diff >>= 1;
    }

    if(t1 == t2) return ans;

    for(int i = 29; i >= 0; i--) {
        if(dp[t1][i] != dp[t2][i]) {
            compare(ans, dist[t1][i]);
            compare(ans, dist[t2][i]);
            t1 = dp[t1][i];
            t2 = dp[t2][i];
        }
    }

    compare(ans, dist[t1][0]);
    compare(ans, dist[t2][0]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back({t2,t3});
        g[t2].push_back({t1,t3});
    }

    DFS(1, 0);
    dpSet();

    int q;
    cin >> q;
    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        pair<int, int> ans = LCA(t1,t2);
        cout << ans.first << " " << ans.second << '\n';
    }

    return 0;
}