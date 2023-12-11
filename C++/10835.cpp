#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int l[2000], r[2000];
int dp[2000][2000];
int go(int a, int b) {
    if(a == n || b == n) return 0;

    int &ret = dp[a][b];
    if(ret != -1) return ret;

    ret = max(go(a + 1, b), go(a + 1, b + 1));
    if(l[a] > r[b]) {
        ret = max(ret, go(a, b + 1) + r[b]);
    }
    return ret;
}
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
    return 0;
}