#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
ll k;
ll dp[12][222][222];
ll go(int idx, int now, int sum) {
    ll &ret = dp[idx][now][sum];
    if(ret != -1) return ret; 

    if(idx == n) {
        if(sum == 0) return ret = 1;
        else return ret = 0;
    }
    if(sum <= 0) return 0;

    ret = 0;
    
    for(int i = now; i <= sum; i++) {
        ret += go(idx + 1, i, sum - i);
    }
    return ret;
}
void tracking(int idx, int now, int sum, ll k) {
    if(idx == n) return ;
    ll sm = 0;
    ll prev = 0; 
    for(int i = now; i <= sum; i++) {
        sm += go(idx + 1, i, sum - i);
        
        if(k < sm) {
            cout << i << ' ';
            tracking(idx + 1, i, sum - i, k - prev);
            return ;
        }
        prev = sm;
    }
}
int main() {
    fastio;
    cin >> n >> m >> k;
    memset(dp,-1,sizeof(dp));
    
    if(k > go(0,1,m)) {
        cout << -1 << '\n';
        return 0;
    }
    k -= 1;
    tracking(0,1,m,k);
    return 0;
}