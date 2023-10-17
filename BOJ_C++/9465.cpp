#include <bits/stdc++.h>
using namespace std;

int a[2][100000];
int dp[100000][3];
int n;

int go(int c, int status) {
    if(c == n) return 0;

    int &ret = dp[c][status];
    if(ret != -1) return ret;
    ret = go(c + 1, 0);
    if(status != 1) ret = max(ret, go(c + 1, 1) + a[0][c]);
    if(status != 2) ret = max(ret, go(c + 1, 2) + a[1][c]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++) {
            dp[i+1][0] = max({dp[i][0], dp[i][1], dp[i][2]});
            dp[i+1][1] = max(dp[i][0], dp[i][2]) + a[0][i];
            dp[i+1][2] = max(dp[i][0], dp[i][1]) + a[1][i];
        }
        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
        
        // memset(dp,-1,sizeof(dp));
        // cout << go(0,0) << '\n';
    }   
     
    return 0;
}