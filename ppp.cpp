#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
string t1, t2;
int dp[5001][5001];

int LCS(int i, int j) {
    if(i < 0 || j < 0) return 0;
    
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    
    if(t1[i] == t2[j]) {
        ret = LCS(i - 1, j - 1) + 1;
    } else {
        ret = max(LCS(i - 1, j), LCS(i, j - 1));
    }
    return ret;
}
void solve() {
    cin >> n >> m >> t1 >> t2;
    memset(dp,-1,sizeof(dp));
    if(LCS(n - 1, m - 1) != m) {
        cout << -1 << '\n';
        return ;
    }


    
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}