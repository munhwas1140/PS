#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w[101];
int v[101];
int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }    
    
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = k; j >= 0; j--) {
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0 && dp[i-1][j-w[i]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
                ans = max(ans, dp[i][j]);
            }
        }
    }     
        
    cout << ans << '\n';

    return 0;
}