#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int r, c;
    cin >> r >> c;
    
    int tr, tc;
    tr = r;
    tc = c;
    ll dark = 0;
    for(int i = 0; tr - i > 0 && tc - i > 0; i++) {
        dark += 2 * ((tr - i) * (tc - i));
    }
    dark -= r * c;

    ll white = 0;

    tr = r - 1;
    tc = c - 1;
    for(int i = 1; tr - i >= 0 && tc - i >= 0; i++) {
        white += (tr - i) * tc;
        white += (tc - i) * tr;
    }
    cout << dark << ' ' << white << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}