#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[200001];
inline int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
        return true;
    }
    return false;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    
    for(int i = 0; i < n; i++) {
        p[i] = -1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(unite(i, a[i])) {
            ans++;
        }
    }
    bool ok = false;
    for(int i = 0; i < n - 1; i++) {
        if(find(a[i]) == find(a[i + 1])) {
            ok = true;
        }
    }
    
    cout << ans + (ok ? -1 : 1) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}