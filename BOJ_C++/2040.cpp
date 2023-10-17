#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n;
int a[3002];
int psum[3002];
int dp[3002];

int go(int idx) {
    if(idx == 0) return 0;

    int &ret = dp[idx];
    if(ret != 1e9) return ret;

    for(int i = 1; i <= idx; i++) {
        ret = min(ret, psum[idx] - psum[i - 1] - go(i - 1));
    }

    return ret;
}

void solve() {
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for(int i = 0; i < 3002; i++) {
        dp[i] = 1e9;
    }
    int ans = go(n);

    if(ans > 0) cout << "B" << '\n';
    else if(ans < 0) cout << "A" << '\n';
    else cout << "D" << '\n';
}

int main() {
    fastio;
    int tc = 3;
    cin >> n;
    while(tc--) {
        solve();
    }
    return 0;
}