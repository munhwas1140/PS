#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int x; cin >> x;
    int a[4];
    vector<bool> check(4, false);
    for(int i = 1; i <= 3; i++) cin >> a[i];
    check[x] = true;
    if(a[x] == 0) {
        cout << "NO" << '\n';
    } else if(!check[a[x]]) {
        check[a[x]] = true;
        if(a[a[x]] == 0) {
            cout << "NO" << '\n';
        } else if(!check[a[a[x]]]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}