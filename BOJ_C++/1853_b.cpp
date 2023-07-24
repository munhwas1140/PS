#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[31][200005];
int fibo[31];
int go(int k, int n) {
    if(k == 0) return 1;
    if(fibo[k] > n) return 0;
    cout << k << ' ' << n << '\n';

    int &ret = dp[k][n];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = fibo[k - 1]; i <= n; i++) {
        ret += go(k - 1, i);
    }
    return ret;
}
void solve() {
    int n, k;
    cin >> n >> k;
    if(n == 0) {
        cout << 1 << '\n';
        return ;
    }

    if(k > 30) cout << 0 << '\n';
    else {
        cout << go(k, n) << '\n';
    }
}
int main() {
    fastio;

    int tc; cin >> tc;
    
    memset(dp,-1,sizeof(dp));
    fibo[2] = 1;
    for(int i = 3; i <= 30; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    for(int i = 1; i <= 5; i++) {
        cout << fibo[i] << ' ';
    }
    cout << '\n';

    while(tc--) {
        solve();
    }

    return 0;
}
