#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        if(l % i) ans[i] = l + i - (l % i);
        else ans[i] = l;
        if(ans[i] > r) {
            cout << "NO" << '\n';
            return ;
        }
    }
    
    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}