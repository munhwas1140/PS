#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
string str;
vector<int> g[2001];
vector<pii> sz[2001];
int dp[2001][2001];
int nexta[2001][2001];
bool visited[2001];
void dfs(int s, int e, int len) {
    visited[e] = true;
    sz[len].push_back({s, e});
    for(int next : g[e]) {
        if(!visited[next]) {
            nexta[next][s] = e;
            dfs(s, next, len + 1);
        }
    }
    visited[e] = false;
}
void init() {
    for(int i = 0; i < 2001; i++) {
        g[i].clear();
        sz[i].clear();
    }
    memset(dp,0,sizeof(dp));
    memset(nexta,0,sizeof(nexta));
    memset(visited,false,sizeof(visited));
}
void solve() {
    init();
    cin >> n >> str;
    str = " " + str;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    for(int i = 1; i <= n; i++) {
        dfs(i, i, 1);
    }

    int ans = 0;
    for(int len = 1; len <= n; len++) {
        for(auto &[s, e] : sz[len]) {

            if(len == 1) {
                dp[s][e] = 1;
            } else if(len == 2) {
                dp[s][e] = 1 + (str[s] == str[e]);
            } else {
                int x = dp[nexta[s][e]][e];
                int y = dp[s][nexta[e][s]];
                int z = dp[nexta[s][e]][nexta[e][s]] + ((str[s] == str[e]) << 1);
                dp[s][e] = max({x, y, z});
            }
            ans = max(ans, dp[s][e]);
        }
    }

    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}