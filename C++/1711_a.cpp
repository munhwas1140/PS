#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return ;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) cout << 2 << ' ';
        else if(i == n - 1) cout << 1 << ' ';
        else cout << i + 2 << ' ';
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