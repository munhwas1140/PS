#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end());
    ll ans = 0;

    for(int i = 0; i < k; i++) {
        ans += a[n - 1 - i].second;
    }

    sort(a.begin(), a.begin() + n - k, [] (pll &u, pll &v) {
        return u.second > v.second;
    });
    for(int i = 0; i < m; i++) {
        ans += a[i].second;
    }
    cout << ans << '\n';

    return 0;
}