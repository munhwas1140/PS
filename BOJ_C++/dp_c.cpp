#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(3));
    int dp[2][3] = {0};
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        auto cur = dp[i % 2], prev = dp[1 - i % 2];
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(j == k) continue;
                cur[j] = max(cur[j], prev[k] + a[i][j]);
            }
        }
    }
    cout << max({dp[n % 2][0], dp[n % 2][1], dp[n % 2][2]}) << '\n';
    return 0;
}