#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), diff;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            diff.push_back(abs(a[i] - a[j]));
        }
    }
    sort(diff.begin(), diff.end());
    if(k == 0) {
        cout << a[0] << '\n';
    } else if(k == 1) {
        cout << min(a[0], diff[0]) << '\n';
    } else if(k == 2) {
        ll ans = min(a[0], diff[0]);
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(diff.begin(), diff.end(), a[i]);
            if(it != diff.end()) ans = min(abs(*it - a[i]), ans);
            if(it != diff.begin()) {
                it--;
                ans = min(abs(*it - a[i]), ans);
            }
        }
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}