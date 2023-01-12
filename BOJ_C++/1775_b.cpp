#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }

    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(auto &x : a[i]) {
            if(cnt[x] == 1) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES" << '\n';
            return ;
        }
    }
    cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}