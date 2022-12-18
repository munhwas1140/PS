#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct C {
    int x, y, r;
};
void solve() {
    int n; cin >> n;
    vector<C> a(n);
    for(auto &[x, y, r] : a) {
        cin >> x >> y >> r;
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}