#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    pii mx = {-1, 0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > mx.first) {
            mx.first = a[i];
            mx.second = (i % 2 == 0);
        } else if(a[i] == mx.first) {
            mx.second |= (i % 2 == 0);
        }
    }
    
    if(mx.second) {
        cout << mx.first + (n + 1) / 2 << '\n';
    } else {
        cout << mx.first + n / 2 << '\n';
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