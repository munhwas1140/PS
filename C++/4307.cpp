#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int l, n;
    cin >> l >> n;
    int minv, maxv;
    minv = -1;
    maxv = -1;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        maxv = max(maxv, max(tmp, l - tmp));
        minv = max(minv, min(tmp, l - tmp));
    }
    cout << minv << ' ' << maxv << '\n';

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}