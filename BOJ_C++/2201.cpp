#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
ll k;
int sz;
ll dp[1000000][3];

void tracking(int sz, ll kth, int prev) {
    if(sz == 0) return ;
    
    if(prev == 0 && dp[sz][0] < kth) {
        cout << 1;
        tracking(sz - 1, kth - dp[sz][0], 1);
    } else {
        cout << 0;
        tracking(sz - 1,kth,0);
    }
}
int main() {
    fastio;
    cin >> k;
    ll sum = 1;
    dp[1][1] = 1;
    for(int i = 2; ;i++) {
        
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-2][1] + dp[i-1][0];       
        sum += dp[i][0] + dp[i][1];
        if(k <= sum) {
            sz = i;
            break;
        }
        
    }
    tracking(sz, k, 0);

    
    return 0;
}