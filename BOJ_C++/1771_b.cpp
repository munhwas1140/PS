#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1, n);
    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        if(s > e) swap(s, e);
        a[s] = min(a[s], e - 1);
    }

    for(int i = n - 1; i > 0; i--) {
        a[i] = min(a[i], a[i + 1]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (ll)(a[i] - i + 1);
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