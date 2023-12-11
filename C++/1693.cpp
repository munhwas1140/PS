#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<vector<int>> gt(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    function<void(int,int)> dfs = [&] (int now, int p) {
        for(int &next : g[now]) {
            if(next == p) continue;
            gt[now].push_back(next);
            dfs(next, now);
        }
    };
    dfs(1, -1);
    
    int h = (int)floor(log2(n));

    vector<vector<int>> dp(n + 1, vector<int>(h + 1, -1));

    int ans = 1e9;
    function<int(int, int)> go = [&] (int now, int color) {
        int &ret = dp[now][color];
        if(ret != -1) return ret;
        ret = color;
        for(int &next : gt[now]) {
            int tmp = 1e9;
            for(int j = 1; j <= h; j++) {
                if(j == color) continue;
                tmp = min(tmp, go(next, j));
            }
            ret += tmp;
        }
        return ret;
    };

    for(int i = 1; i <= h; i++) {
        ans = min(ans, go(1, i));
    }
    
    cout << ans << '\n';

    return 0;
}