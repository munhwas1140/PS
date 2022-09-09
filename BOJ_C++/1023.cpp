#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
ll k;
ll dp[51][51];
ll go(int idx, int open) {
    if(idx == n) return 1;
    
    ll &ret = dp[idx][open];
    if(ret != -1) return ret;
    ret = 0;

    ret += go(idx + 1, open + 1);
    ret += go(idx + 1, open);

    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    cout << go(0,0);
    // if(k > go(0,0)) return !(cout << -1 << '\n'); 
      
    return 0;
}
