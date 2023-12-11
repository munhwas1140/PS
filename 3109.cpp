#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    function<bool(int, int)> go = [&] (int x, int y) {
        if(y == m - 1) return true;
        a[x][y] = 'x';
        for(int i = -1; i <= 1; i++) {
            if(x + i < 0 || x + i >= n || a[x + i][y + 1] == 'x') continue;
            if(go(x + i, y + 1)) return true;
        }
        return false;
    };

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += go(i, 0);
    }
    cout << ans << '\n';
    return 0;
}