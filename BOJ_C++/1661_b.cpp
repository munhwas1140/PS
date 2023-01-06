#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 32768;
int dp[MOD + 1];

int go(int now) {
    if(now == 0) {
        return 0;
    }
    
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1e9;

    ret = min(go((now * 2) % MOD), go((now + 1) % MOD)) + 1;
    return ret;
}

int main() {
    fastio;

    memset(dp,-1,sizeof(dp));
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cout << go(tmp) << ' ';
    }
    return 0;
}