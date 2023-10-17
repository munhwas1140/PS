#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int dp[1500001];
int t[1500001];
int c[1500001];
int go(int now) {
    if(now == n) return 0;
    if(now > n) return -1e9;
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = go(now + 1);
    ret = max(ret, go(now + t[now]) + c[now]);
    return ret;
}
int main() {
    fastio;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> c[i];
    }
    cout << go(0) << '\n';
    return 0;
}