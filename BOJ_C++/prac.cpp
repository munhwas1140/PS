#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1, 0LL);
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll maxv = *max_element(a.begin(), a.end());

    if(n == 2) {
        cout << max(sum, abs(a[1] - a[2]) * 2) << '\n';
    } else if(n == 3) {
        if(a[1] == maxv || a[3] == maxv) {
            cout << maxv * 3LL << '\n';
        } else {
            ll ans = sum;
            ans = max(ans, abs(a[1] - a[2]) * 2 + a[3]);
            ans = max(ans, abs(a[2] - a[3]) * 2 + a[1]);
            ans = max(ans, abs(a[1] - a[2]) * 3);
            ans = max(ans, abs(a[2] - a[3]) * 3);
            ans = max(ans, abs(a[1] - a[3]) * 3);
            ans = max(ans, a[1] * 3);
            ans = max(ans, a[3] * 3);
            ans = max(ans, abs(a[1] - a[2]) + abs(abs(a[1] - a[2]) - a[3]) * 2);
            ans = max(ans, abs(a[2] - a[3]) + abs(abs(a[2] - a[3]) - a[1]) * 2);
            cout << ans << '\n';
        }
    } else {
        cout << maxv * n << '\n';
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