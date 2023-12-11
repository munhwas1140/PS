// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;

// int main() {
//     fastio;
//     int tc; cin >> tc;
//     while(tc--) {
//         int n; cin >> n;
//         vector<int> a(n);
//         for(int i = 0; i < n; i++) cin >> a[i];
//         vector<int> cnt(n);
//         int s, e;
//         s = e = 0;
//         while(1) {
//             if(s >= n) break;
//             if(e >= n) {
//                 cnt[s] = e - s;
//                 s++;
//             } else if(a[e] > e - s) {
//                 e++;
//             } else {
//                 cnt[s] = e - s;
//                 s++;
//             }
//         }
//         ll ans = 0;
//         for(int i = 0; i < n; i++) {
//             ans += (ll)cnt[i];
//         }
//         cout << ans << '\n';

//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    ll n; cin >> n;
    vector<ll> dp(n + 5);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        dp[i] = min(dp[i - 1] + 1, x);
        ans += dp[i];
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}