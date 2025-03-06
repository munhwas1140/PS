#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;

int n;
int a[100001];
vector<int> g[100001];

int dp[100001][10][2];

int go(int now, int mx, int visit, int p) {
    int &ret = dp[now][mx][visit];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    for (int next : g[now]) {
        if (next == p) continue;
        if (a[next] >= mx) {
            ret += go(next, a[next], 1, now);
            ret %= MOD;
        }
        ret += go(next, mx, 0, now);
        ret %= MOD;
    }

    ret += visit;
    ret %= MOD;
    return ret;
}

int main() {
    fastio;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    a[0] = 0;
    g[0].push_back(1);
    g[1].push_back(0);

    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0, -1) << '\n';

    return 0;
}