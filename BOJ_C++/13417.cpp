#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string ans;
    cin >> ans;
    for(int i = 1; i < n; i++) {
        char tmp; cin >> tmp;
        if(tmp <= ans[0]) {
            ans = tmp + ans;
        } else {
            ans += tmp;
        }
    }
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