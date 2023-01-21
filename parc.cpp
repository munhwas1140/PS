#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> idx(100001, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }
    vector<vector<int>> pos(n, vector<int>(1, 1));
    for(int i = 2; i <= m; i++) {
        for(int j = 0; j <= 100000; j+= i) {
            if(idx[j] != -1) {
                pos[idx[j]].push_back(i);
            }
        }
    }

    vector<int> cnt(m + 1);
    int s, e;
    s = e = 0;

    int now = 0;
    for(int x : pos[0]) {
        cnt[x]++;
        now++;
    }
    int ans = 1e9;
    while(s <= e && e < n) {
        if(now == m) {
            ans = min(ans, a[e] - a[s]);
            for(int x : pos[s]) {
                cnt[x]--;
                if(cnt[x] == 0) now--;
            }
            s++;
        } else {
            e++;
            if(e == n) break;
            for(int x : pos[e]) {
                cnt[x]++;
                if(cnt[x] == 1) now++;
            }
        }
    }
    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }   
    return 0;
}