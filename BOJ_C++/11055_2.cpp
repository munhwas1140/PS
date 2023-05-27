#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[1001];
int dp[1001];
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for(int j = 1; j <= i; j++) {
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}