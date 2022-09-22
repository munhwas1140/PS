#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        
        string a, b;
        cin >> a >> b;
        vector<int> diff;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) diff.push_back(i);
        }

        if(diff.size() % 2) {
            cout << -1 << '\n';
            continue;
        }

        if(diff.size() >= 4) {
            cout << (diff.size() / 2) * y << '\n';
        } else if(diff.size() == 2) {
            if(diff[0] + 1 == diff[1]) {
                cout << min(x, 2 * y) << '\n';
            } else {
                cout << y << '\n';
            }
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}