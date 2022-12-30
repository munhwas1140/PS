#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<tuple<int,int,int>> a(n);
    vector<int> comp;
    for(auto &[s, e, t] : a) {
        cin >> s >> e >> t;
        comp.push_back(s);
        comp.push_back(e);
    }
    
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    int sz = comp.size();
    vector<vector<pii>> v(sz);
    for(auto &[s, e, t] : a) {
        s = lower_bound(comp.begin(), comp.end(), s) - comp.begin();
        e = lower_bound(comp.begin(), comp.end(), e) - comp.begin();
        v[e].push_back({s, t});
    }

    vector<int> dp(sz);
    for(int i = 1; i < sz; i++) {
        dp[i] = dp[i - 1];
        for(auto &[s, t] : v[i]) {
            dp[i] = max(dp[i], dp[s - 1] + t);
        }
    }
    cout << dp[sz - 1] << '\n';
    return 0;
}