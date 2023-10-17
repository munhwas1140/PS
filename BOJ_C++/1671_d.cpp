#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += abs(a[i + 1] - a[i]);
    }

    {
        ll miv = min(a[0] - 1, a[n - 1] - 1);
        for(int i = 0; i < n; i++) {
            miv = min(miv, 2 * (a[i] - 1));
        }
        ans += miv;
    }

    ll mx = *max_element(a.begin(), a.end());
    if(mx < x) {
        ll mn = min(x - a[0], x - a[n - 1]);
        for(int i = 0; i < n; i++) {
            mn = min(mn, 2 * (x - a[i]));
        }
        ans += mn;
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