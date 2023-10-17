#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
double dp[1001][2002];
int n, m;
double go(int day, int climbed) {
    if(day == n) {
        if(climbed >= m) return 1.0;
        return 0;
    }
    double &ret = dp[day][climbed];
    if(ret != 1e9) return ret;
    ret = 0;
    ret += 0.75 * go(day + 1, climbed + 2);
    ret += 0.25 * go(day + 1, climbed + 1);
    return ret;
}
void solve() {
    cin >> m >> n;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m * 2; j++) {
            dp[i][j] = 1e9;
        }
    }
    cout << fixed << setprecision(10);
    cout << go(0, 0) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}