#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int r, c, x1, y1, x2, y2;
    cin >> r >> c >> x1 >> y1 >> x2 >> y2;
    map<pii, int> cnt;
    if(r == c) {
        int dx[] = {r, -r};
        int dy[] = {c, -c};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cnt[make_pair(x1 + dx[i], y1 + dy[j])]++;
                cnt[make_pair(x2 + dx[i], y2 + dy[j])]++;
            }
        }

    } else {
        int dx[] = {r, -r};
        int dy[] = {c, -c};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                cnt[make_pair(x1 + dx[i], y1 + dy[j])]++;
                cnt[make_pair(x2 + dx[i], y2 + dy[j])]++;
                cnt[make_pair(x1 + dy[i], y1 + dx[j])]++;
                cnt[make_pair(x2 + dy[i], y2 + dx[j])]++;
            }
        }
    }

    int ans = 0;
    for(auto it : cnt) {
        if(it.second == 2) ans++;
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}