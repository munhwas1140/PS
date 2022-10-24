#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int w[20], v[20];
int dp[201];

void solve() {
    cin >> n >> m;
    m /= 100;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        w[i] /= 100;
    }
    
    memset(dp,0,sizeof(dp));
    int ret = 0;
    for(int i = 1; i <= m; i++) {
        int cand = 0;
        for(int j = 0; j < n; j++) {
            if(i - w[j] >= 0) {
                cand = max(cand, dp[(i - w[j]) % 201] + v[j]);
            }
        }
        dp[i % 201] = cand;
        ret = max(ret, cand);
    }
    cout << ret << '\n';
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