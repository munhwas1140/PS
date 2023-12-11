// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// int n;
// int a[100001];
// int psum[100001];
// ll dp[100001][5];
// int main() {
//     fastio;
//     cin >> n;
//     int sum = 0;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//         psum[i] = psum[i - 1] + a[i];
//     }
    
//     if(psum[n] % 4) {
//         cout << 0 << '\n';
//     } else {
//         ll tar = psum[n] / 4;
//         dp[0][0] = 1;
//         for(int i = 1; i <= n; i++) {
//             dp[i][0] = 1;
//             for(int j = 1; j <= 3; j++) {
//                 dp[i][j] = dp[i - 1][j];
//                 if(tar * j == psum[i]) {
//                     dp[i][j] += dp[i - 1][j - 1];
//                 }
//             }
//         }
//         cout << dp[n - 1][3];
//     }
//     return 0;
// }

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
    vector<ll> dp(4);
    for(auto &x : a) cin >> x;
    for(int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    
    ll tar = a[n - 1];
    if(tar % 4) return !(cout << 0 << '\n');
    tar /= 4;
    
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == tar * 3) dp[2] += dp[1];
        if(a[i] == tar * 2) dp[1] += dp[0];
        if(a[i] == tar) dp[0]++;
    }
    cout << dp[2] << '\n';

    return 0;
}