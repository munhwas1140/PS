#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, w;
int a[2][10001];
int dp[10001][4];
int go(int idx, int s) {
    if(idx == n) return 0;
    if(idx == n - 1) {
        if(s == 0) {
            if(a[0][idx] + a[1][idx] <= w) return 1;
            int tmp = 2;
            if(a[0][idx] == 1e9) tmp--;
            if(a[1][idx] == 1e9) tmp--;
            return tmp;
        } else if(s == 1) {
            if(a[1][idx] == 1e9) return 0;
            return 1;
        } else if(s == 2) {
            if(a[0][idx] == 1e9) return 0;
            return 1;
        } 
        return 0;
    }

    int &ret = dp[idx][s];
    if(ret != -1) return ret;

    if(s == 0) {
        ret = go(idx + 1, 0) + 2;
        if(a[0][idx] + a[1][idx] <= w) ret = min(ret, go(idx + 1, 0) + 1);
        if(idx + 1 < n) {
            if(a[0][idx] + a[0][idx + 1] <= w) {
                ret = min(ret, go(idx + 1, 1) + 2);
                if(a[1][idx] + a[1][idx + 1] <= w) {
                    ret = min(ret, go(idx + 1, 3) + 2);
                }
            } 
            if(a[1][idx] + a[1][idx + 1] <= w) {
                ret = min(ret, go(idx + 1, 2) + 2);
            }
        }
    } else if(s == 1) {
        ret = go(idx + 1, 0) + 1;
        if(idx + 1 < n) {
            if(a[1][idx] + a[1][idx + 1] <= w) {
                ret = min(ret, go(idx + 1, 2) + 1);
            }
        }
    } else if(s == 2) {
        ret = go(idx + 1, 0) + 1;
        if(idx + 1 < n) {
            if(a[0][idx] + a[0][idx + 1] <= w) {
                ret = min(ret, go(idx + 1, 1) + 1);
            }
        }
    } else {
        ret = go(idx + 1, 0);
    }

    return ret;
}
void solve() {
    cin >> n >> w;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    int ans = go(0, 0);
    int t1 = a[0][0], t2 = a[0][n - 1];
    int t3 = a[1][0], t4 = a[1][n - 1];

    if(a[0][0] + a[0][n - 1] <= w) {
        a[0][0] = a[0][n - 1] = 1e9;
        memset(dp,-1,sizeof(dp));
        ans = min(ans, go(0, 1) + 1);
        if(a[1][0] + a[1][n - 1] <= w) {
            a[1][0] = a[1][n - 1] = 1e9;
            memset(dp,-1,sizeof(dp));
            ans = min(ans, go(0, 3) + 2);
        }
    } 

    a[0][0] = t1; a[0][n - 1] = t2; a[1][0] = t3; a[1][n - 1] = t4;
    if(a[1][0] + a[1][n - 1] <= w) {
        a[1][0] = a[1][n - 1] = 1e9;
        memset(dp,-1,sizeof(dp));
        ans = min(ans, go(0, 2) + 1);
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}