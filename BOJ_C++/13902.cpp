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
    vector<int> a(m);
    vector<int> pos;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        pos.push_back(a[i]);
    }
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(a[i] + a[j] <= 10000) pos.push_back(a[i] + a[j]);
        }
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    vector<int> dp(n + 1, -1);
    
    function<int(int)> go = [&] (int now) {
        if(now == 0) return 0;
        if(now < 0) return (int)1e9;

        int &ret = dp[now];
        if(ret != -1) return ret;

        ret = 1e9;
        for(int &x : pos) {
            if(x > now) continue;
            ret = min(ret, go(now - x) + 1);
        }
        return ret;
    };
    
    int ans = go(n);
    if(ans >= 1e9) {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;
}