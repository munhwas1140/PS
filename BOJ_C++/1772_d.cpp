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

    int e = 1e9;
    int s = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] < a[i + 1]) {
            e = min(e, (a[i] + a[i + 1]) / 2);
        } else if(a[i] > a[i + 1]) {
            s = max(s, (a[i] + a[i + 1] + 1) / 2);
        }
    }
    if(s > e) cout << -1 << '\n';
    else cout << s << '\n';

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}