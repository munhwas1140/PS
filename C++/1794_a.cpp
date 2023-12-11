#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n;
    cin >> n;
    string ans = "";
    for(int i = 0; i < 2 * n - 2; i++) {
        string tmp; cin >> tmp;
        if(tmp.size() == n - 1) {
            if(ans == "") {
                ans = tmp;
            } else {
                bool ok = true;
                for(int i = 0; i < n - 2; i++) {
                    if(ans[i + 1] != tmp[i]) {
                        ok = false;
                    }
                }

                if(ok) ans += tmp.back();
                else ans = tmp[0] + ans;
            }
        }
    }

    for(int i = 0; i < n / 2; i++) {
        if(ans[i] != ans[n - 1 - i]) {
            cout << "NO" << '\n';
            return ;
        }
    }
    cout << "YES" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}