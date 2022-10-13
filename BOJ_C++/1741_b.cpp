#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    if(n == 2) {
        cout << 2 << ' ' << 1 << '\n';
        return ;
    } else if(n == 3) {
        cout << -1 << '\n';
        return ;
    }
    
    vector<int> a(n);
    if(n >= 4) {
        for(int i = 0; i < n - 2; i++) {
            a[i] = 3 + i;
        }
        a[n - 2] = 2;
        a[n - 1] = 1;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}