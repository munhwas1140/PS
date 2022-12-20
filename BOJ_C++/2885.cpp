#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    int one = 0, sz = 0;
    int last = __builtin_ctz(n);
    while(n) {
        sz++;
        one += (n % 2);
        n /= 2;
    }
    if(one == 1) {
        cout << (1 << (sz - 1)) << ' ' << 0 << '\n';
    } else {
        cout << (1 << sz) << ' ' << sz - last << '\n';
    }
    return 0;
}