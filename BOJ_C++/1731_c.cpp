#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n; cin >> n;
    vector<int> a(n), m(2 * n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll cnt = 0;
    int curr = 0;
    m[curr]++;

    for(int j = 0; j < n; j++) {
        curr ^= a[j];
        for(ll i = 0; i * i < 2 * n; i++) {
            if((curr ^ (i * i)) < 2 * n) {
                cnt += m[curr ^ (i * i)];
            }
        }
        m[curr]++;
    }
    ll ans = ((n * (n + 1)) / 2) - cnt;
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