#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1000001];
int go(int now) {
    if(now == 1) return 0;
    
    int &ret = dp[now];
    if(ret != -1) return ret;

    ret = go(now - 1) + 1;
    if(now % 3 == 0) ret = min(ret, go(now / 3) + 1);
    if(now % 2 == 0) ret = min(ret, go(now / 2) + 1);
    return ret;
}
int main() {
    fastio;
    int n; cin >> n;

    memset(dp,-1,sizeof(dp));
    cout << go(n) << '\n';
    return 0;
}