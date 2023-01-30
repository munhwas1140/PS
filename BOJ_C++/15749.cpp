#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<pii> b(m);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(auto &[f, d] : b) cin >> f >> d;

    vector<vector<int>> dp(n + 1, vector<int>(m, -1));

    function<int(int, int)> go = [&] (int now, int idx) {
        if(now == n) return 0; 

        int &ret = dp[now][idx];
        if(ret != -1) return ret;
        ret = 10000;

        if(idx + 1 < m && a[now] <= b[idx + 1].first) {
            ret = min(ret, go(now, idx + 1) + 1);
        }

        for(int i = 1; i <= b[idx].second; i++) {
            if(now + i > n) break;
            if(a[now + i] <= b[idx].first) ret = min(ret, go(now + i, idx));
        }

        return ret;
    };
    
    cout << go(1, 0) << '\n';

    return 0;
}