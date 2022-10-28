#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;

    sort(a.begin(), a.end(), [](pii p1, pii p2) {
        return p1.second > p2.second;
    });

    int ans = 0;
    int range = 0;
    for(int i = 0; i < n; i++) {
        range += a[i].first;
        ans = max(ans, range + a[i].second);
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