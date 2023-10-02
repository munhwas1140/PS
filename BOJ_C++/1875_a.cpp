#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        b += min(a - 1, x[i]);
    }
    cout << b << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}