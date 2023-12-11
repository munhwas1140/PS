#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int dp[10001];
int a[101];

int main() {
    fastio;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = a[i]; j <= k; j++) {
            if(dp[j - a[i]] != -1) {
                if(dp[j] == -1 || dp[j] > dp[j - a[i]] + 1) {
                    dp[j] = dp[j - a[i]] + 1;
                }
            }
        }
    }
    cout << dp[k] << '\n';
    return 0;
}