#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, c;
int a[13];
int dp[10][1 << 13];
int go(int idx, int state) {
    if(idx == m) return 0;
    int &ret = dp[idx][state];
    if(ret != -1) return ret;
    ret = 0;

    int pos = ((1 << n) - 1) - state;
    for(int i = pos; i; i = ((i - 1) & pos)) {
        int sum = 0, cnt = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                cnt++;
                sum += a[j];
            }
        }
        if(sum <= c) {
            ret = max(ret, go(idx + 1, state | i) + cnt);
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << go(0, 0) << '\n';
    return 0;
}