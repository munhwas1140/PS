#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[111], dp[111][111], p[111][111];
void init() {
    for(int i = 0; i < 111; i++) {
        for(int j = 0; j < 111; j++) {
            dp[i][j] = 1e9;
            p[i][j] = -1;
            if(i == j) dp[i][j] = 0;
        }
        a[i] = 0;
    }
}
int MIN(int a, int b) {
    return a > b ? b : a;
}
void trace(int i, int j) {
    if(i == j) cout << "M" << i;
    else {
        cout << "(";
        trace(i, p[i][j]);
        trace(p[i][j] + 1, j);
        cout << ")";
    }
}
void solve() {
    init();

    int n; cin >> n;
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    for(int dia = 1; dia < n; dia++) {
        for(int i = 1; i <= n - dia; i++) {
            int j = i + dia;
            for(int k = i; k <= j - 1; k++) {
                if(dp[i][j] > dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
                    p[i][j] = k;
                }
            }
        }
    }

    trace(1, n);
    cout << '\n';
    cout << dp[1][n] << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}   