#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int go(vector<int> &a, int s, int m, int sz) {
    if(sz == 1) return 0;
    int ret = 0;
    bool l, r;
    l = r = false;
    for(int i = s; i < s + sz / 2; i++) {
        if(a[i] <= m) l = true;
        else r = true;
    }

    if(l && r) return -1e9;
    int nm;
    if(l) {
        nm = sz / 4;
    } else {
        nm = -(sz / 4);
        ret = 1;
    }

    ret += go(a, s, m - nm, sz / 2);
    ret += go(a, s + sz / 2, m + nm, sz / 2);
    return ret;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = go(a, 1, (1 + n) / 2, n);
    if(ans < 0) ans = -1;
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