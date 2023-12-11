#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) a[i] = i;

    cout << n << '\n';
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
    
    for(int i = 1; i < n; i++) {
        swap(a[i], a[n]);
        for(int j = 1; j <= n; j++) {
            cout << a[j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}