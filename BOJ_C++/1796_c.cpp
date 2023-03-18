#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 998244353;
int l, r;
void solve() {
    cin >> l >> r;
    
    int sz = 1;
    for(int tmp = l; tmp <= r; tmp *= 2, sz++);
    sz--;

    int x = pow(2, sz - 1);
    int ans = (r / x) - l + 1;
    if(x >= 2 && (r / ((x / 2) * 3)) >= l) {
        ans += ((r / ((x / 2) * 3)) - l + 1) * (sz - 1);
    }
    cout << sz << ' ' << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}