#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int dp[301][301][301];
int a[301];
int go(int x, int y, int rem) {
    if(x == -1) {
        if(y == 0 && rem == 0) return 0;
        return -1e9;
    }
    if(y == 0) {
        if(rem == 0) return 0;
        return -1e9;
    }

    int &ret = dp[x][y][rem];
    if(ret != -1) return ret;

    ret = go(x - 1, y, rem);
    ret = max(ret, go(x, y - 1, (rem - a[x] + k * 301) % k) + a[x]);
    return ret;
}
int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = max(ans, go(n - 1, i, 0));
    }
    cout << ans << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
int dp[301][301];
int a[301];
int main() {
    fastio;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < 301; i++) {
        for(int j = 0; j < 301; j++) {
            dp[i][j] = -1e9;
        }
    }

    dp[0][0] = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            for(int x = 0; x < n; x++) {
                dp[i + 1][(j + a[x]) % k] = max(dp[i + 1][(j + a[x]) % k], dp[i][j] + a[x]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << '\n';

    return 0;
}