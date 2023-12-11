#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
const int MOD = 5000000;
int a[100001];
int dp[100001][51];
int tree[51][100001];
int sum(int now, int sz) {
    if(sz == 0) return 1;
    int ret = 0;
    for(; now >= 1; now -= (now & -now)) {
        ret += tree[sz][now];
        ret %= MOD;
    }
    return ret;
}
void update(int now, int sz, int val) {
    for(; now <= 100000; now += (now & -now)) {
        tree[sz][now] += val;
        tree[sz][now] %= MOD;
    }
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = sum(a[i] - 1, j - 1);
            dp[i][j] %= MOD;
            update(a[i], j, dp[i][j]);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i][k];
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}