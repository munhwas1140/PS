#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, s;
int a[101];
int dp[101][11];
int pSum[101];
int sqSum[101];
void init() {
    pSum[0] = a[0];
    sqSum[0] = a[0] * a[0];
    for(int i = 1; i < n; i++) {
        pSum[i] = pSum[i - 1] + a[i];
        sqSum[i] = sqSum[i - 1] + a[i] * a[i];
    }
}
int calc(int s, int e) {
    int sum = pSum[e] - (s == 0 ? 0 : pSum[s - 1]);
    int sqsum = sqSum[e] - (s == 0 ? 0 : sqSum[s - 1]);
    
    int m = int(0.5 + (double)sum / (e - s + 1));
    int ret = sqsum - 2 * m * sum + m * m * (e - s + 1);
    return ret;
}
int go(int idx, int num) {
    if(idx == n) return 0;
    if(num == 0) return 1e9;
    int &ret = dp[idx][num];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int sz = 1; idx + sz <= n; sz++) {
        ret = min(ret, calc(idx, idx + sz - 1) + go(idx + sz, num - 1));
    }
    return ret;
}
void solve() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    init();
    memset(dp,-1,sizeof(dp));
    cout << go(0,s) << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}