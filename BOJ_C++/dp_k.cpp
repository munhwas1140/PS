#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int a[101];
int dp[100001];
int go(int now) {

    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= now) {
            ret = max(ret, 1 - go(now - a[i]));
        }
    }
    return ret;
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = go(k);
    if(ans) cout << "First" << '\n';
    else cout << "Second" << '\n';

    return 0;
}