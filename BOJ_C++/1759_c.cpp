#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int l, r, x;
    cin >> l >> r >> x;
    int s, e;
    cin >> s >> e;

    if(s == e) {
        cout << 0 << '\n';
        return ;
    }

    if(e > s) {
        if(e - s >= x && s + x <= r) cout << 1 << '\n';
        else if((r >= s + x && r - x >= e) || (l <= s - x && l + x <= e)) cout << 2 << '\n';
        else if((s + x <= r && l + x <= e) || (s - x >= l && r - x >= e)) cout << 3 << '\n';
        else cout << -1 << '\n';
    } else {
        if(s - e >= x && s - x >= l) cout << 1 << '\n';
        else if((r >= s + x && r - x >= e) || (l <= s - x && l + x <= e)) cout << 2 << '\n';
        else if((s + x <= r && l + x <= e) || (s - x >= l && r - x >= e)) cout << 3 << '\n';
        else cout << -1 << '\n';
    }
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}