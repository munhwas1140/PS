#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<pii> g[200001];
int n;
void init() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
int go(int now, int pre, int preid) {
    int ret = 1;
    for(auto &[next, nextid] : g[now]) {
        if(next == pre) continue;
        if(nextid < preid) {
            ret = max(ret, go(next, now, nextid) + 1);
        } else ret = max(ret, go(next, now, nextid));
    }
    return ret;
}
void solve() {
    cin >> n;
    init();
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back({t2, i});
        g[t2].push_back({t1, i});
    }
    cout << go(1, -1, -1) << '\n';
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}