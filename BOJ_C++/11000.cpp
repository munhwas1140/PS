#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a;
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a.push_back({t1, 1});
        a.push_back({t2, -1});
    }

    sort(a.begin(), a.end());
    int ans = 0;
    int now = 0;
    for(auto &[x, d] : a) {
        now += d;
        ans = max(ans, now);
    }
    cout << ans << '\n';
    return 0;
}