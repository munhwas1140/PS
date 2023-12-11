#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, dp[101];
vector<pii> a;
int go(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1;

    int tmp = 0;
    for(int i = now + 1; i < n; i++) {
        if(a[now].second >= a[i].second) {
            tmp = max(tmp, go(i));
        }
    }

    ret += tmp;
    return ret;
}
int main() {
    fastio;
    cin >> n;
    a.resize(n);
    for(auto &[x, y] : a) {
        cin >> x >> y;
        if(x < y) swap(x, y);
    }

    sort(a.rbegin(), a.rend());
    memset(dp,-1,sizeof(dp));

    int ans = -1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, go(i));
    }

    cout << ans << '\n';

    return 0;
}