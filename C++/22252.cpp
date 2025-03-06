#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    cin >> n;

    map<string, priority_queue<ll>> mp;
    ll ans = 0LL;
    while (n--) {
        int q, cnt;
        string name;
        cin >> q >> name >> cnt;
        if (q == 1) {
            if (mp.count(name) == 0) {
                mp[name] = priority_queue<ll>();
            }
            for (int i = 0; i < cnt; i++) {
                int t;
                cin >> t;
                mp[name].push(t);
            }
        } else {
            for (int i = 0; i < cnt; i++) {
                if (mp[name].empty()) {
                    break;
                }
                ans += mp[name].top();
                mp[name].pop();
            }
        }
    }
    cout << ans << '\n';

    return 0;
}