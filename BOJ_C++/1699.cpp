#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;   

    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = i;
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i- j*j] + 1);
        }
    }
    cout << dp[n] << '\n';  
    
    return 0;
}