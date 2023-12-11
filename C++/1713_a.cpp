#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    int ans = 0;
    int mxx, mxy, mix, miy;
    mxx = mxy = mix = miy = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(x < 0) mix = min(mix, x);
        if(x > 0) mxx = max(mxx, x);
        if(y < 0) miy = min(miy, y);
        if(y > 0) mxy = max(mxy, y);
    }
    cout << 2 * mxx + 2 * mxy + -2 * miy + -2 * mix << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}