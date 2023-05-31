#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;
    ll ans = 0;
    vector<map<int,int>> cnt(2 * n + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= (2 * n) / a[i].first; j++) {
            if(cnt[j].find(a[i].first * j - a[i].second) != cnt[j].end()) {
                ans += ll(cnt[j][a[i].first * j - a[i].second]);
            } 
        }
        cnt[a[i].first][a[i].second]++;
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
// ans += ll(cnt[j][a[i].first * j - a[i].second]);
// 0이더라도 계속 생겨서 메모리 초과됨