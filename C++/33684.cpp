#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] > k) {
        cout << 0 << '\n';
        return 0;
    } else if (a[0] <= 0) {
        cout << -1 << '\n';
        return 0;
    }

    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        ans += ll(k - a[i]) / a[0];
    }
    cout << ans + 1 << '\n';

    return 0;
}
