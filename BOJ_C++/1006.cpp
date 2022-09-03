#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
//
// dp[size][up- down][4, 0 하나 1 하나, 위, 3 하나 오른쪽];
int dp[10000][4];
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n, w;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n, 0));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
         a[0].push_back(a[0][0]);
        a[1].push_back(a[1][0]);
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i = 0; i < n; i++) {
            if(a[1][i] + a[0][i] <= w) dp[i+1][0] = dp[i][0] + 1;
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + 2);
            dp[i+1][0] = min(dp[i+1][0],min(dp[i][1], dp[i][2]) + 1);
        
            
            if(a[1][i] + a[1][i+1] <= w) {
                dp[i+1][1] = dp[i][0] + 2;
                dp[i+1][1] = min(dp[i+1][1], dp[i][2] + 1);
            }

            if(a[0][i] + a[0][i+1] <= w) {
                dp[i+1][2] = dp[i][0] + 2;
                dp[i+1][2] = min(dp[i+1][2], dp[i][1] + 1);
            }
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    }     
      
    return 0;
}