#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[101][101][2];
int go(int n, int k, int state) { 
    if(n == 1) {
        return k == 0;
    }

    int &ret = dp[n][k][state];
    if(ret != -1) return ret;
    ret = 0;

    if(state == 1) {
        ret += go(n - 1, k - 1, 1);
        ret += go(n - 1, k, 0);
    } else {
        ret += go(n - 1, k, 0);
        ret += go(n - 1, k, 1);
    }
    return ret;
}
void solve() {
    int n, k;
    cin >> n >> k;
    cout << go(n, k, 0) + go(n, k, 1) << '\n';
}

int main() {
    fastio;

    
    memset(dp,-1,sizeof(dp));
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}