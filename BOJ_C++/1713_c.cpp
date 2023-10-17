#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> ans(n);
    function<void(int)> go = [&] (int r) {
        if(r < 0) return ;
        int s = sqrt(2 * r); s *= s;
        int l = s - r; go(l - 1);
        for(; l <= r; l++, r--) {
            ans[l] = r;
            ans[r] = l;
        }
    };
    go(n - 1);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}