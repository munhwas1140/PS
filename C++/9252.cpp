#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string a, b;
int n, m;
int dp[1001][1001];
int go(int ai, int bi) {
    if(ai == -1 || bi == -1) return 0;
    int &ret = dp[ai][bi];
    if(ret != -1) return ret;
    if(a[ai] == b[bi]) ret = go(ai - 1, bi - 1) + 1;
    else {
        ret = max(go(ai - 1, bi), go(ai, bi - 1));
    }
    return ret;
}
void trace(int i, int j) {
    if(i == -1 || j == -1) return ;
    if(a[i] == b[j]) {
        trace(i - 1, j - 1);
        cout << a[i];
        return ;
    } else {
        if(go(i - 1, j) < go(i, j - 1)) {
            trace(i, j - 1);
        } else {
            trace(i - 1, j);
        }
    }
}
int main() {
    fastio;
    cin >> a >> b;
    n = a.size(); m = b.size();
    memset(dp,-1,sizeof(dp));
    cout << go(n - 1, m - 1) << '\n';
    trace(n - 1, m - 1);
    cout << '\n';
    return 0;
}