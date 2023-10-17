#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, i + 1 + a[i]);
    }
    cout << ans + 1 << '\n';
    return 0;
}