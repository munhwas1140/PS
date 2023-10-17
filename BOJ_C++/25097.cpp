#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    for(int TC = 1; TC <= tc; TC++) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n + 1, vector<int>(2));
        vector<vector<ll>> dp(n + 1, vector<ll>(2));

        for(int i = 1; i <= n; i++) {
            a[i][0] = 1e9 + 1;
            a[i][1] = -1;
            for(int j = 0; j < k; j++) {
                int tmp; cin >> tmp;
                a[i][0] = min(a[i][0], tmp);
                a[i][1] = max(a[i][1], tmp);
            }
        }

        for(int i = 1; i <= n; i++) {
            int pmn = a[i - 1][0], pmx = a[i - 1][1];

            if(pmn > a[i][1]) dp[i][0] = dp[i-1][0] + pmn - a[i][0];
            else dp[i][0] = dp[i-1][0] + a[i][1] - a[i][0] + a[i][1] - pmn;

            if(pmx > a[i][1]) dp[i][0] = min(dp[i][0], dp[i-1][1] + pmx - a[i][0]);
            else dp[i][0] = min(dp[i][0], dp[i-1][1] + a[i][1] - a[i][0] + a[i][1] - pmx);

            if(pmn < a[i][0]) dp[i][1] = dp[i-1][0] + a[i][1] - pmn;
            else dp[i][1] = dp[i-1][0] + a[i][1] - a[i][0] + pmn - a[i][0];

            if(pmx < a[i][0]) dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i][1] - pmx);
            else dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i][1] - a[i][0] + pmx - a[i][0]); 
        }
        cout << "Case #" << TC << ": ";
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}