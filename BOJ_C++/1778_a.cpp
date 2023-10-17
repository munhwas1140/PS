#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int mx = -4;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != a[i + 1]) mx = max(mx, 0);
        if(a[i] == -1) {
            if(a[i + 1] == -1) {
                mx = 4;
            }
        }
    }
    cout << sum + mx << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}