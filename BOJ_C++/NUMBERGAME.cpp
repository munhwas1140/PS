#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, a[50];
int dp[50][50];
int go(int l, int r) {
    if(l > r) return 0;
    int &ret = dp[l][r];
    if(ret != -1e9) return ret;

    ret = max(a[l] - go(l + 1, r), a[r] - go(l, r - 1));
    if(r - l + 1 >= 2) {
        ret = max(ret, -go(l + 2, r));
        ret = max(ret, -go(l, r - 2));
    }
    return ret;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            dp[i][j] = -1e9;
        }
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