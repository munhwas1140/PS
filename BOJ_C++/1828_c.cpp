#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    ll ans = 1;
    for(int i = 0; i < n; i++) {
        int t = a.size() - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
        ans = (ans * max(t - i, 0)) % MOD;
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