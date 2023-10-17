#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int n; cin >> n;

    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        if(i == 0) continue;
        g[t].push_back(i);
    }

    vector<int> dp(n, -1);
    function<int(int)> go = [&] (int now) {
        int &ret = dp[now];
        if(ret != -1) return ret;

        int sz = g[now].size();
        if(sz == 0) return ret = 0;
        else {
            vector<int> tmp(sz);
            for(int i = 0; i < sz; i++) {
                tmp[i] = go(g[now][i]);
            }
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < sz; i++) {
                tmp[i] += sz - i;
            }
            return ret = *max_element(tmp.begin(), tmp.end());
        }
    };

    cout << go(0) << '\n';

    return 0;
}