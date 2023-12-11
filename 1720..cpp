#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int dp[31];
int go(int now) {
    if(now == 0) return 1;

    int &ret = dp[now];
    if(ret != -1) return ret;

    ret = go(now - 1);
    if(now >= 2) {
        ret += go(now - 2) * 2;
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    int t1 = go(n);
    if(n % 2 == 0) {
        t1 += go(n / 2);
        t1 += go((n / 2) - 1) * 2;
    } else {
        t1 += go(n / 2);
    }
    cout << t1 / 2 << '\n';

    return 0;
}