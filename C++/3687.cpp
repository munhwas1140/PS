#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int tmp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// 2 5 5 4 5 6 3 7 6 6
ll dp[101];
void init() {
    int a[8] = {-1, -1, 1, 7, 4, 2, 0, 8};
    for(int i = 0; i < 8; i++) {
        dp[i] = a[i];
    }
    dp[6] = 6;
    dp[8] = 10;
    for(int i = 9; i <= 100; i++) {
        dp[i] = 1000000000000000000LL;
        for(int j = 2; j <= 7; j++) {
            dp[i] = min(dp[i], dp[i - j] * 10 + a[j]);
        }
    }
}
void solve() {
    cin >> n;
    cout << dp[n] << ' ';
    if(n % 2) {
        cout << 7;
        for(int i = 0; i < (n - 3) / 2; i++) {
            cout << 1;
        }
    } else {
        for(int i = 0; i < n / 2; i++) {
            cout << 1;
        }
    }
    cout << '\n';
}
int main() {
    init();
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}