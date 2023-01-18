#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[] = {25, 10, 5, 1};
void solve() {
    int n; cin >> n;
    for(int i = 0; i < 4; i++) {
        cout << n / a[i] << ' ';
        n %= a[i];
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