#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(2, vector<int>(n + 1));
    vector<vector<int>> b(2, vector<int>(n + 1));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(i + j > 0) a[i][j]++;
        }
    }

    b[0][n] = b[1][n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int k = 0; k < 2; k++) {
            b[k][i] = max({a[k ^ 1][i], a[k][i] + 2 * (n - i) - 1, b[k][i + 1] + 1});
        }
    }

    int ans = 2e9;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int k = i & 1;
        ans = min(ans, max(cur, b[k][i]));
        cur = max(cur, a[k][i] + 2 * (n - i) - 1);
        cur = max(cur, a[k ^ 1][i] + 2 * (n - i) - 2);
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