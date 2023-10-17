#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n, 1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        for(int j = (i - k >= 0 ? i - k : 0); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}