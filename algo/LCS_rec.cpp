#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[111][111];
string s1, s2;
int MAX(int a, int b) {
    return a > b ? a : b;
}
void init() {
    for(int i = 0; i < 111; i++) {
        for(int j = 0; j < 111; j++) {
            dp[i][j] = -1;
        }
    }
}
int go(int n, int m) {
    if(n == 0 || m == 0) return 0;
    int &ret = dp[n][m];
    if(ret != -1) return ret;

    if(s1[n - 1] == s2[m - 1]) {
        return ret = go(n - 1, m - 1) + 1;
    } else {
        return ret = MAX(go(n - 1, m), go(n, m - 1));
    }
}
void solve() {
    init();
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    cout << go(n, m) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}