#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[100][100][2000];
int n, k, x;
int main() {
    fastio;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> a[i] >> tmp;
    }

    sort(a.begin() + 1, a.end());
    memset(dp,-1,sizeof(dp));

    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = k; j >= 0; j--) {
            for(int l = k * x; l >= 0; l--) {
                dp[i][j][l] |= dp[i-1][j][l];
                if(l - a[i] >= 0) {
                    dp[i][j][l] |= dp[i-1][j-1][l-a[i]];
                }
            }
        }
    }

    int ans = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k * x; j++) {
            if(dp[i][k][j]) {
                ans = max(ans, j * (k * x - j));
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}