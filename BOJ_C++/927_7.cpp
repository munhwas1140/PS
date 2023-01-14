#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    vector<pii> ans;
    for(int i = 0; i <= n; i++) {
        if(a[i] % 2 && i + x <= n && a[i + x] % 2) {
            ans.push_back({i, i + x});
        }
    }
    
    if(ans.size() == 1) {
        cout << "YES" << '\n';
        cout << ans[0].first << ' ' << ans[0].second << '\n';
    } else cout << "NO" << '\n';
    return 0;
}