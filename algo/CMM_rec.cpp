#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[111];
int dp[111][111];
void init() {
    for(int i = 0; i < 111; i++) {
        for(int j = 0; j < 111; j++) {
            dp[i][j] = -1;
        }
        a[i] = 0;
    }
}
int go(int i, int j) {
    if(i == j) return 0;
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int k = i; k < j; k++) {
        ret = min(ret, go(i, k) + go(k + 1, j) + a[i] * a[k + 1] * a[j + 1]);
    }
    return ret;
}
void solve() {
    init();
    cin >> n;
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    cout << go(0, n - 1) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}