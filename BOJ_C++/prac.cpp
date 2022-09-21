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
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        string t1, t2;
        cin >> t1 >> t2;
        t1 = " " + t1;
        t2 = " " + t2;
        vector<int> diff;
        for(int i = 1; i <= n; i++) {
            if(t1[i] != t2[i]) {
                diff.push_back(i);
            }
        }
        if(diff.size() % 2) {
            cout << -1 << '\n';
            continue;
        }
        ll ans = 0;
        int m = diff.size() / 2;
        for(int i = 0; i < m; i++) {
            int p1 = diff[i];
            int p2 = diff[i + m];
            if(p1 + 1 == p2) {
                if(y * 2 <= x) {
                    ans += y * 2;
                } else {
                    ans += x;
                }
            } else {
                ans += y;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}