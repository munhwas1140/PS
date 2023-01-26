#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll ans = 0;
        while(true) {
            int n; cin >> n;
            if(n == 0) break;
            ll tmp = (1 << n) - 1;
            cout << "- " << tmp << '\n';
            cout.flush();
            ans += tmp;
        }
        cout << "! " << ans << '\n';
        cout.flush();
    }
    return 0;
}