#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    if(n == k) {
        cout << 0 << '\n';
    } else {
        int ans = 0;
        for(int i = 0; i < k; i++) {
            if(pos[i] >= k) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}