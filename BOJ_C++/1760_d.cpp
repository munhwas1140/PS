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
    int s = 0;
    int cnt = 0;
    while(s < n) {
        int e = s;
        while(e + 1 < n && a[e] == a[e + 1]) e++;

        if(s == 0 || a[s - 1] > a[s]) {
            if(e == n - 1 || a[e + 1] > a[e]) cnt++;
        }
        s = e + 1;
    }
    cout << (cnt == 1 ? "Yes" : "No") << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}