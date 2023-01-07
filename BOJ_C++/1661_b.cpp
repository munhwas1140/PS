#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 32768;
int dp[32769];
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));

    dp[0] = 0;
    queue<int> q;

    q.push(0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto y : {(x - 1 + MOD) % MOD, x & 1 ? 0 : (x >> 1 | 16384), x & 1 ? 0 : (x >> 1)}) {
            if(dp[y] == -1) {
                dp[y] = dp[x] + 1;
                q.push(y);
            }
        }
    }

    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        cout << dp[t] << ' ';
    }

    return 0;
}