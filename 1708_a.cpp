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
    if(a[0] == 1) {
        cout << "YES" << '\n';
        return ;
    }

    for(int i = 1; i < n; i++) {
        if(a[i] % a[0] || a[i] < a[0]) {
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