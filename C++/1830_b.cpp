#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int a[200001], b[200001];
int cnt[200001];
vector<int> v[200001];
void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) v[i].clear();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0;

    for(int i = 1; i * i <= 2 * n; i++) {
        for(int j = 1; j <= n; j++) cnt[j] = 0;
        
        for(int idx : v[i]) {
            ll tmp = 1LL * i * a[idx] - b[idx];
            if(1 <= tmp && tmp <= n) ans += cnt[tmp];
            cnt[b[idx]]++;
        }
        for(int j = i + 1; j <= n; j++) {
            for(int idx : v[j]) {
                ll tmp = 1LL * i * a[idx] - b[idx];
                if(1 <= tmp && tmp <= n) ans += cnt[tmp];
            }
        }
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