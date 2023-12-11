#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;
int main() {
    fastio;
    int n; cin >> n;
    vector<vector<pair<int, ll>>> g(n + 1);
    vector<vector<pair<int, ll>>> gt(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        ll cost;
        cin >> t1 >> t2 >> cost;
        g[t1].push_back({t2, cost});
        g[t2].push_back({t1, cost});
    }

    function<void(int, int)> dfs = [&] (int now, int p) {
        for(auto &[next, cost] : g[now]) {
            if(next == p) continue;
            gt[now].push_back({next, cost});
            dfs(next, now);
        }
    };
    dfs(1, -1);

    vector<ll> dp1(n + 1, -1);
    vector<ll> dp2(n + 1, -1);

    function<ll(int)> go1 = [&] (int now) {
        ll &ret = dp1[now];
        if(ret != -1) return ret;
        ret = 0;
        for(auto &[next, cost] : gt[now]) {
            ret += (go1(next) + 1) * cost;
            ret %= MOD;
        }
        return ret;
    };

    function<ll(int)> go2 = [&] (int now) {
        ll &ret = dp2[now];
        if(ret != -1) return ret;
        ret = go1(now);

        int sz = gt[now].size();
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                ll t1 = (go1(gt[now][i].first) + 1) * gt[now][i].second;
                t1 %= MOD;

                ll t2 = (go1(gt[now][j].first) + 1) * gt[now][j].second;
                t2 %= MOD;

                ret += t1 * t2;
                ret %= MOD;
            }
            ret += go2(gt[now][i].first);
            ret %= MOD;
        }

        return ret;
    };

    cout << go2(1) << '\n';

    return 0;
}