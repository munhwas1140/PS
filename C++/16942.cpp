#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1000];
int n;
string str;
int go(int idx) {

    int &ret = dp[idx];
    if(ret != -1) return ret;
    ret = 1;

    for(int i = 1; idx + i < n; i+= 2) {
        if(str[idx + i] == str[idx]) {
            ret = max(ret, go(idx + i) + 1);
        };
    }
    return ret;
}
int main() {
    fastio;
    cin >> str;
    n = str.size();
    memset(dp,-1,sizeof(dp));
    
    int ans = 1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, go(i));
    }
    cout << ans << '\n';
    return 0;
}