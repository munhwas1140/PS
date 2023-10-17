#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, q;
int dep[100001];
int dp[100001][20];
vector<int> g[100001];
void dfs(int now) {
    for(int i = 0; i < g[now].size(); i++) {
        int next = g[now][i];
        dep[next] = dep[now] + 1;
        dfs(next);
    }
}
int LCA(int t1, int t2) {
    
    int ans = 0;
    if(dep[t1] < dep[t2]) {
        swap(t1, t2);
    }

    // t1 below

    int diff = dep[t1] - dep[t2];
    for(int i = 19; i >= 0; i--) {
        if(diff & (1 << i)) {
            ans += (1 << i);
            t1 = dp[t1][i];
        }
    }

    if(t1 == t2) {
        return ans;
    }


    for(int i = 19; i >= 0; i--) {
        if(dp[t1][i] != dp[t2][i]) {
            ans += (1 << (i + 1));
            t1 = dp[t1][i];
            t2 = dp[t2][i];
        }
    }
    return ans + 2;
}
void init() {
    memset(dp,-1,sizeof(dp));
    memset(dep,0,sizeof(dep));
    for(int i = 0; i < 100001; i++) {
        g[i].clear();
    }
}
void solve() {
    cin >> n >> q;
    init();
    for(int i = 1; i < n; i++) {
        int tmp; cin >> tmp;
        g[tmp].push_back(i);
        dp[i][0] = tmp;
    }
    dfs(0);


    for(int i = 1; i < 20; i++) {
        for(int j = 1; j < n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    
    while(q--) {
        int t1, t2;
        cin >> t1 >> t2;
        cout << LCA(t1, t2) << '\n';
    }
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}