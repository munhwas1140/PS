#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int y, m;
    cin >> y >> m;
    if(m == 1) {
        cout << y - 1 << ' ' << 12 << ' ' << 31 << '\n';
    } else if(m == 3) {
        int tmp = 28;
        if(y % 4 == 0) {
            if(y % 100 == 0) {
                if(y % 400 == 0) tmp = 29;
            } else tmp = 29;
        }
        cout << y << ' ' << 2 << ' ' << tmp << '\n';
    } else {
        int tmp = 31;
        if(m == 5 || m == 7 || m == 10 || m == 12) tmp = 30;
        cout << y << ' ' << m - 1 << ' ' << tmp << '\n';
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