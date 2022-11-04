#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int c, n;
int w[20], v[20];
int dp[1001][21];
int go(int num, int idx) {
    if(num >= c) return 0;
    if(idx == n) return 1e9;

    int &ret = dp[num][idx];
    if(ret != -1) return ret;

    ret = 1e9;
    for(int i = 0; ; i++) {
        ret = min(ret, go(num + v[idx] * i, idx + 1) + w[idx] * i);
        if(num + v[idx] * i >= c) break;
    }
    return ret;
}
int main() {
    fastio;
    cin >> c >> n;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << go(0, 0) << '\n';

    return 0;
}