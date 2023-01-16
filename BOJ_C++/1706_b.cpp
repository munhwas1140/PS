#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> pos(n + 1), a(n + 1), ans(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(pos[a[i]] == 0) {
            ans[a[i]]++;
        } else {
            if((i - pos[a[i]]) % 2 == 1) {
                ans[a[i]]++;
            }
        }
        pos[a[i]] = i;
    }

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