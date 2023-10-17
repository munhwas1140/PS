#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll a[200000], b[200000];
void solve() {
    int n; cin >> n;
    int lim = int(floor(sqrt(2 * n)));
    vector<vector<int>> cnt(lim + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(a[i] <= lim) {
            cnt[a[i]][b[i]]++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= lim) {
            // a[i] == a[j], a[i] * a[i] - b[i];
            // if(a[i] * a[i] - b[i] <= n) to cnt col size -> 2 * n + 1
            if(a[i] * a[i] - b[i] >= 0 && a[i] * a[i] - b[i] <= n) {
                ans += cnt[a[i]][a[i] * a[i] - b[i]];
            }
        }
    }
    for(int i = 2; i <= lim; i += 2) {
        ans -= cnt[i][(i * i) / 2];
    }
    ans /= 2;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= lim && j < a[i] && j * a[i] <= 2 * n; j++) {
            if(a[i] * j - b[i] >= 0 && a[i] * j - b[i] <= n) {
                ans += cnt[j][a[i] * j - b[i]];
            }
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