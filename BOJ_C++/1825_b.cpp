#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    int sz = n * m;
    vector<int> a(sz);
    for(int i = 0; i < sz; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    if(n == 1) {
        cout << (a[sz - 1] - a[0]) * (m - 1) << '\n';
    } else if(m == 1) {
        cout << (a[sz - 1] - a[0]) * (n - 1) << '\n';
    } else {
        ll ans = (a[sz - 1] - a[0]) * (n - 1) * (m - 1);
        int tmp = max(a[sz - 1] - a[1], a[sz - 2] - a[0]);
        if(n > m) {
            ans += (a[sz - 1] - a[0]) * (n - 1);
            ans += tmp * (m - 1);
        } else {
            ans += (a[sz - 1] - a[0]) * (m - 1);
            ans += tmp * (n - 1);
        }
        cout << ans << '\n';
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