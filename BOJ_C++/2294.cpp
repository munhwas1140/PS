// #include <bits/stdc++.h>
// using namespace std;

// int cost[101];
// int dp[101][10001];
// int N, K;
// int go(int n, int k) {
//     if(n == N) return (k == 0 ? 0 : 1e9);

//     int &ret = dp[n][k];
//     if(ret != -1) return ret;

//     ret = go(n + 1, k);
//     if(k >= cost[n]) ret = min(ret, go(n, k - cost[n]) + 1); 
//     return ret;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     cin >> N >> K;
//     for(int i = 0; i < N; i++) {
//         cin >> cost[i];
//     }
//     memset(dp,-1,sizeof(dp));
    
//     int ans = go(0, K);
//     if(ans == 1e9) cout << -1 << '\n';
//     else cout << ans << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int a[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j - a[i] >= 0 && dp[j-a[i]] != -1) {
                if(dp[j] == -1 || dp[j] > dp[j - a[i]] + 1) {
                    dp[j] = dp[j - a[i]] + 1;
                }
            }
        }
    }
    
    cout << dp[k];


     
    return 0;
}