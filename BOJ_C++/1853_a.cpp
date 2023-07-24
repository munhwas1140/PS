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

    int mndif = 1e9;
    for(int i = 0; i < n - 1; i++) {
        int diff = a[i + 1] - a[i];
        if(diff < 0) {
            cout << 0 << '\n';
            return ;
        }
        mndif = min(diff, mndif);
    }
    cout << (mndif / 2) + 1 << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}