#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int gcd;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) {
            gcd = a[i];
        } else {
            gcd = std::gcd(a[i], gcd);
        }
    }
    
    if(gcd == 1) {
        cout << a[n - 1] << '\n';
    } else {
        cout << a[n - 1] / gcd << '\n';
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