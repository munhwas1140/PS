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

    int cnt = 0;
    for(int i = 0; i <= n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] > i) cnt++;
        }
        if(cnt == i) {
            cout << i << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}