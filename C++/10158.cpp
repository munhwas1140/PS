#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int t; cin >> t;
    x += t;
    y += t;
    if((x / n) % 2) {
        x %= n;
        x = n - x;
    } else {
        x %= n;
    }

    if((y / m) % 2) {
        y %= m;
        y = m - y;
    } else {
        y %= m;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}