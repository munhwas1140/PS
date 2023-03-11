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
    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        reverse(a.begin() + x, a.begin() + y + 1);
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}