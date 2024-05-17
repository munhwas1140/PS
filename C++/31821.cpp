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

    int m; cin >> m;
    int ans = 0;

    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        ans += a[tmp - 1];
    }
    cout << ans << '\n';
    return 0;
}
