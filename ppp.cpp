#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;

    vector<int> a(n + 1), b(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<pii> ans;
    for(int i = 1; i <= n; i++) {
        int idx = i;
        for(int j = i; j <= n; j++) {
            if(a[idx] > a[j]) {
                idx = j;
            } else if(a[idx] == a[j]) {
                if(b[idx] > b[j]) {
                    idx = j;
                }
            }
        }
        if(i != idx) {
            swap(a[i], a[idx]);
            swap(b[i], b[idx]);
            ans.push_back({i, idx});
        }
    }

    for(int i = 1; i < n; i++) {
        if(b[i] > b[i + 1]) {
            cout << -1 << '\n';
            return ;
        }
    }

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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