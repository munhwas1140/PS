#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 998244353;
int n, a[301];
int dp[301][300 * 300 * 2 + 1];
int go(int idx, int now) {
    if(idx == n) return 1;

    int &ret = dp[idx][now + 90000];
    if(ret != -1) return ret;

    ret = go(idx + 1, a[idx] + now);
    if(now != 0) {
        ret += go(idx + 1, a[idx] - now);
        ret %= MOD;
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << go(2, a[1]) << '\n';
    return 0;
}