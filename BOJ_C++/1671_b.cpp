#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool f1, f2, f3;
    f1 = f2 = f3 = false;
    bool ok = true;
    for(int i = 1; i < n; i++) {
        int diff = a[i] - a[i - 1];

        if(diff == 2) {
            if(!f1) f1 = true;
            else {
                if(!f2) f2 = true;
                else ok = false;
            }
        } else if(diff == 3) {
            if(f1 || f2) {
                ok = false;
            } else {
                f1 = f2 = true;
            }
        } else if(diff > 3) {
            ok = false;
        }
    }
    
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}