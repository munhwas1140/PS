#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n), ans(n);
    vector<bool> check(n);

    for(int &x : a) cin >> x;

    for(int i = 1; i <= n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            if(check[j]) continue;
            if(a[j] == 0) {
                check[j] = true;
                ans[j] = i;
                for(int k = j + 1; k < n; k++) {
                    if(check[k]) continue;
                    a[k]--;
                    if(a[k] < 0) {
                        cout << "IMPOSSIBLE" << '\n';
                        return ;
                    }
                }
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] == 0) {
            cout << "IMPOSSIBLE" << '\n';
            return ;
        }
    }

    for(int i = 0; i < n; i++) {
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