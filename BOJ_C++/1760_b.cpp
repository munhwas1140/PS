#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n;
    string str;
    cin >> n >> str;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, str[i] - 'a');
    }
    cout << ans + 1 << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}