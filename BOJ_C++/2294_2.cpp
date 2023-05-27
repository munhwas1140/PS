#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int dp[101][10001];
int a[101];

int go(int idx, int val) {
    if(val < 0) return 1e9;
    if(idx == 0) {
        if(val == 0) return 0;
        return 1e9;
    }
    
    int &ret = dp[idx][val];
    if(ret != -1) return ret;

    ret = min(go(idx - 1, val), go(idx, val - a[idx]) + 1);
    return ret;
}

int main() {
    fastio;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(n, k) << '\n';

    return 0;
}