#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int a[5001], dp[5001];
int go(int now) {

    int &ret = dp[now];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < now; i++) {
        int cal = (now - i) * (1 + abs(a[i] - a[now]));
        if(cal <= k) {
            if(go(i)) return 1;
        }
    }
    return ret;
}

int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    dp[0] = 1;
    cout << (go(n - 1) ? "YES" : "NO") << '\n';
    return 0;
}