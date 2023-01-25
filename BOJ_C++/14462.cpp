// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// int dp[1001][1001];
// int main() {
//     fastio;
//     int n; cin >> n;

//     vector<int> pos(n + 1);
//     for(int i = 1; i <= n; i++) {
//         int tmp; cin >> tmp;
//         pos[tmp] = i;
//     }

//     vector<vector<int>> a(n);
//     for(int i = 0; i < n; i++) {
//         int tmp; cin >> tmp;
//         for(int j = max(tmp - 4, 1); j <= min(tmp + 4, n); j++) {
//             a[i].push_back(pos[j]);
//         }
//         sort(a[i].begin(), a[i].end());
//     }

//     memset(dp,-1,sizeof(dp));
//     function<int(int, int)> go = [&] (int idx, int now) {
//         if(idx == n) return 0;

//         int &ret = dp[idx][now];
//         if(ret != -1) return ret;

//         ret = go(idx + 1, now);
//         for(int next : a[idx]) {
//             if(next > now) {
//                 ret = max(ret, go(idx + 1, next) + 1);
//             }
//         }   
//         return ret;
        
//     };


//     cout << go(0, 0);
//     return 0;
// }

// // 1 2 3 4 5 6
// // 6 5 4 3 2 1

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> l(n + 1), r(n + 1);
    vector<vector<int>> dp(n + 1,vector<int>(n + 1));

    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> r[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(abs(l[i] - r[j]) <= 4) dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}