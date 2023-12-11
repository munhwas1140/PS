#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + tmp;
        }
    }     

    while(m--) {
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        cout << dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1] << '\n';
    }
      
    return 0;
}