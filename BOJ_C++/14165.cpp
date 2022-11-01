#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int N, M, K;
const int MOD = 1e9 + 9;
int a[1001], b[1001];
int dp[1001][1001][11];
int go(int n, int m, int k) {
    if(n >= N || m >= M) return 0;

    int &ret = dp[n][m][k];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = n; i < N; i++) {
        for(int j = m; j < M; j++) {
            if(a[i] > a[j]) {
                if(k == 1) ret++;
                else {
                    ret += go(i + 1, j + 1, k - 1);
                }
                ret %= MOD;
            }
        }
    }

    return ret;
}
int main() {
    fastio;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];
    sort(a, a + N);
    sort(b, b + M);
    memset(dp,-1,sizeof(dp));
    cout << go(0, 0, K) << '\n';
    return 0;
}