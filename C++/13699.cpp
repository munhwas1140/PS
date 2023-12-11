#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll dp[36];
ll go(int n) {
    if(n == 0) return 1;
    if(n == 1 || n == 2) return n;

    ll &ret = dp[n];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        ret += go(i) * go(n - 1 - i);
    }

    return ret;
}
int main() {
    fastio;
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << go(n) << '\n';
    return 0;
}