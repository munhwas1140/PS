#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pii> ans;
    bool ok = true;
    for(ll i = 1; i < n; i += 2) {
        ll a = i;
        ll b = i + 1;
        if(((a + k) * b) % 4 == 0) {
            ans.push_back({i, i + 1});
            continue;
        }
        if(((b + k) * a) % 4 == 0) {
            ans.push_back({i + 1, i});
            continue;
        }
        ok = false;
        break;
    }

    if(ok) {
        cout << "YES" << '\n';
        for(auto &[x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    } else {
        cout << "NO" << '\n';
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