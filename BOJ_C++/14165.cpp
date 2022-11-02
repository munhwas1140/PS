// #include <bits/stdc++.h>
// using namespace std;
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// const unsigned int MOD = 1e9 + 9;
// int N, M, K;
// int a[1001], b[1001];
// unsigned int dp[1001][1001][11], rSum[1001][1001][11];
// int main() {
//     fastio;
//     cin >> N >> M >> K;
//     for(int i = 0; i < N; i++) cin >> a[i];
//     for(int i = 0; i < M; i++) cin >> b[i];
//     sort(a, a + N);
//     sort(b, b + M);

//     for(int k = 0; k < K; k++) {
//         for(int i = 0; i < N; i++) {
//             for(int j = 0; j < M; j++) {
//                 if(a[i] > b[j]) {
//                     dp[i][j][k] = (k > 0 ? rSum[i][j][k - 1] : 1);
//                 }
//             }
//         }

//         for(int i = 0; i < N; i++) {
//             for(int j = 0; j < M; j++) {
//                 rSum[i+1][j+1][k] = (rSum[i][j+1][k] + rSum[i+1][j][k] - rSum[i][j][k] + dp[i][j][k] + MOD) % MOD;
//             }
//         }
//     }
//     cout << rSum[N][M][K - 1] << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 9;
int a[1001], b[1001];
int dp[1001][1001][11];
int N, M, K;
int go(int n, int m, int k) {
    if(k == 0) return 1;
    if(n >= N || m >= M) return 0;

    int &ret = dp[n][m][k];
    if(ret != -1) return ret;

    ret = (go(n + 1, m, k) + go(n, m + 1, k)) % MOD;
    ret += (MOD - go(n + 1, m + 1, k));
    ret %= MOD;
    if(a[n] > b[m]) {
        ret += go(n + 1, m + 1, k - 1);
        ret %= MOD;
    }
    return ret;
}
int main() {
    fastio;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int j = 0; j < M; j++) cin >> b[j];
    sort(a, a + N);
    sort(b, b + M);

    memset(dp,-1,sizeof(dp));
    cout << go(0, 0, K) << '\n';
    return 0;
}