#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pos;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(pos.begin(), pos.end(), a[i]);
        if(it == pos.end()) {
            pos.push_back(a[i]);
            if(pos.size() == 2) ans++;
        } else {
            if(pos.size() >= 2 && it == pos.begin() + 1) ans++;
            *it = a[i];
        }
    }
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