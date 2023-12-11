#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    cin >> n;
    vector<pll> a(n);
    for(auto &[x, y] : a) {
        cin >> x >> y;
    }

    ll sum = 0;
    for(int i = 0; i < n - 1; i++) {
        auto &[x1, y1] = a[i];
        auto &[x2, y2] = a[i + 1];
        sum += abs(x1 - x2) + abs(y1 - y2);
    }
    if(sum % 2) {
        cout << "YES" << '\n';
        for(int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}