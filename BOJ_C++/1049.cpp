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

    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a[0] >= b[0] * 6) {
        cout << b[0] * n << '\n';
    } else {
        int x = a[0] * (n / 6) + b[0] * (n % 6);
        int y = a[0] * ((n / 6) + 1);
        cout << min(x, y) << '\n';
    }

    return 0;
}