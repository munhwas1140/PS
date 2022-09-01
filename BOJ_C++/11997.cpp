#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int m[1001][1001];
int main() {
    fastio;
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> x, y;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        x.push_back(a[i].first); y.push_back(a[i].second);
    } 
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(),x.end()), x.end());
    y.erase(unique(y.begin(),y.end()), y.end());
    
    for(int i = 0; i < n; i++) {
        int t1 = lower_bound(x.begin(), x.end(), a[i].first) - x.begin();
        int t2 = lower_bound(y.begin(), y.end(), a[i].second) - y.begin();
        m[t1][t2] = 1;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + m[i][j];
        }
    }

    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int t3 = dp[i][j];
            int t1 = dp[i][n] - t3;
            int t2 = dp[n][j] - t3;
            int t4 = dp[n][n] - t1 - t2 - t3;
            ans = min(ans, max({t1,t2,t3,t4}));
        }
    } 
    cout << ans << '\n';
      
    return 0;
}