#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
double dp[3000][3000];
double a[3000];
double go(int n, int m) {
    if(m < 0 || n + 1 <= m) return 0.0;
    if(n == 0) return 1.0;
    
    double &ret = dp[n][m];
    if(ret != -1.0) return ret;
    
    ret = go(n - 1, m) * (1 - a[n]);
    ret += go(n - 1, m - 1) * a[n];
    return ret;
}
int main() {
    fastio;
    for(int i = 0; i < 3000; i++) {
        for(int j = 0; j < 3000; j++) {
            dp[i][j] = -1.0;
        }
    }
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double ans = 0;
    for(int i = n / 2 + 1; i <= n; i++) {
        ans += go(n, i);
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
    return 0;
}