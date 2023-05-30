#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a >> b;
        cout << (a + b - 1) / b << '\n';
    }

    return 0;
}