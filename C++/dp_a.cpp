#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    for(int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i-1]), dp[i-2] + abs(a[i] - a[i-2]));
    }

    cout << dp[n - 1] << '\n';

    return 0;
}