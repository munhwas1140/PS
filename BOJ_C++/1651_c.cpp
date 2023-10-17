#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(2, vector<ll>(n));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    

    ll ans = 1e18;
    ans = min(ans, abs(a[0][0] - a[1][0]) + abs(a[0][n - 1] - a[1][n - 1]));
    ans = min(ans, abs(a[0][0] - a[1][n - 1]) + abs(a[0][n - 1] - a[1][0]));
    
    ll tmp = abs(a[0][0] - a[1][0]);
    ll t1, t2;
    t1 = t2 = 1e18;
    for(int i = 0; i < n; i++) {
        t1 = min(t1, abs(a[0][n - 1] - a[1][i]));
        t2 = min(t2, abs(a[1][n - 1] - a[0][i]));
    }
    tmp += t1 + t2;
    ans = min(ans, tmp);


    tmp = abs(a[0][0] - a[1][n - 1]);
    t1 = t2 = 1e18;
    for(int i = 0; i < n; i++) {
        t1 = min(t1, abs(a[0][n - 1] - a[1][i]));
        t2 = min(t2, abs(a[1][0] - a[0][i]));
    }
    tmp += t1 + t2;
    ans = min(ans, tmp);

    tmp = abs(a[0][n - 1] - a[1][0]);
    t1 = t2 = 1e18;
    for(int i = 0; i < n; i++) {
        t1 = min(t1, abs(a[0][0] - a[1][i]));
        t2 = min(t2, abs(a[1][n - 1] - a[0][i]));
    }
    tmp += t1 + t2;
    ans = min(ans, tmp);

    tmp = abs(a[0][n - 1] - a[1][n - 1]);
    t1 = t2 = 1e18;
    for(int i = 0; i < n; i++) {
        t1 = min(t1, abs(a[0][0] - a[1][i]));
        t2 = min(t2, abs(a[1][0] - a[0][i]));
    }
    tmp += t1 + t2;
    ans = min(ans, tmp);

    tmp = 0;
    ll t3, t4;
    t1 = t2 = t3 = t4 = 1e18;
    for(int i = 0; i < n; i++) {
        t1 = min(t1, abs(a[0][0] - a[1][i]));
        t2 = min(t2, abs(a[0][n - 1] - a[1][i]));
        t3 = min(t3, abs(a[1][0] - a[0][i]));
        t4 = min(t4, abs(a[1][n - 1] - a[0][i]));
    }
    ans = min(ans, t1 + t2 + t3 + t4);
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}