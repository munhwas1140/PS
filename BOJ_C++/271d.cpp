#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, s;
int a[101];
int b[101];
int dp[101][10001];
int p[101][10001];
bool go(int idx, int sum) {
    int &ret = dp[idx][sum];
    if(ret != -1) return ret;

    if(idx == n) {
        if(sum == s) return ret = 1;
        return ret = 0;
    }
    if(sum > s) return false;

    if(go(idx + 1, sum + a[idx])) {
        return ret = true;
    }
    if(go(idx + 1, sum + b[idx])) {
        return ret = true;
    }
    return ret = false;
}
void trace(int idx, int sum) {
    if(idx == n) return ;
    
    if(dp[idx + 1][sum + a[idx]] == 1) {
        cout << "H";
        trace(idx + 1, sum + a[idx]);
        return ;
    }
    if(dp[idx + 1][sum + b[idx]] == 1) {
        cout << "T";
        trace(idx + 1, sum + b[idx]);
        return ;
    }
    return ;
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    memset(p,-1,sizeof(p));
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    

    if(go(0,0) == 0) return !(cout << "No" << '\n');
    cout << "Yes" << '\n';
    trace(0, 0);

    return 0;
}