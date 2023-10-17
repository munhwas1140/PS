// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// int n, k;
// const int MOD = 998244353;
// int main() {
//     fastio;
//     cin >> n >> k;
//     vector<int> dp(n + 1), ans(n + 1);
//     dp[0] = 1;
//     for(int i = 0; i + k <= n; i += k++) {
//         vector<int> sum(k);

//         for(int j = i; j <= n; j++) {
//             int cur = dp[j];
//             dp[j] = sum[j % k];
//             sum[j % k] += cur;
//             sum[j % k] %= MOD;

//             ans[j] += dp[j];
//             ans[j] %= MOD;
//         }
//         for(int j = 0; j <= n; j++) {
//             cout << dp[j] << ' ';
//         }
//         cout << '\n';
//         // for(int j = 0; j <= n; j++) {
//         //     cout << sum[j] << ' ';
//         // }
//         // cout << '\n';
//         cout << '\n';
//     }
//     for(int i = 0; i <= n; i++) {
//         cout << ans[i] << ' ';
//     }
//     cout << '\n';

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 998244353;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> ans(n + 1), dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i + k <= n; i += k++) {
        vector<int> sum(k);
        for(int j = i; j <= n; j++) {
            int cur = dp[j];
            dp[j] = sum[j % k];

            sum[j % k] += cur;
            sum[j % k] %= MOD;

            ans[j] += dp[j];
            ans[j] %= MOD;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}