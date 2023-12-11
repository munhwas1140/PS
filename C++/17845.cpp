#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int v[1001];
int w[1001];
int dp[10001];
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> v[i] >> w[i];
    }

    for(int i = 0; i < k; i++) {
        for(int j = n; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}