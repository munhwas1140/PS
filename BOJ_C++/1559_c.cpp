#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if(a[1] == 1) {
        cout << n + 1 << ' ';
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
    } else if(a[n] == 0) {
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << n + 1 << '\n';
    } else {
        for(int i = 1; i <= n - 1; i++) {
            if(a[i] == 0 && a[i + 1] == 1) {
                for(int j = 1; j <= i; j++) {
                    cout << j << ' ';
                }
                cout << n + 1 << ' ';
                for(int j = i + 1; j <= n; j++) {
                    cout << j << ' ';
                }
                cout << '\n';
                return ;
            }
        }
        cout << -1 << '\n';
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