#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int v[21][301]; // v[i][j], i기업 j원 투자시.
int dp[21][301];

int go(int idx, int val) {
    if(idx == 0) {
        if(val == 0) return 0;
        return -1e9;
    }
    int &ret = dp[idx][val];
    if(ret != -1) return ret;

    ret = go(idx - 1, val);
    
    for(int i = 1; i <= val; i++) {
        ret = max(ret, go(idx - 1, val - i) + v[idx][i]);
    }
    return ret;
}

void trace(int idx, int val) {
    if(idx == 0) return ;

    int tmp = go(idx - 1, val);
    int ret = 0;
    for(int i = 1; i <= val; i++) {
        if(tmp < go(idx - 1, val - i) + v[idx][i]) {
            tmp = go(idx - 1, val - i) + v[idx][i];
            ret = i;
        }
    }

    trace(idx - 1, val - ret);
    cout << ret << ' ';
}
int main() {
    fastio; 
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        for(int j = 1; j <= m; j++) {
            cin >> v[j][i];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << go(m, n) << '\n';

    trace(m, n);
    return 0;
}