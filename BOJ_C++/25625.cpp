#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int x, y;
    cin >> x >> y;
    if((y / x) % 2 == 0) {
        cout << x + y % x << '\n';
    } else {
        cout << y % x << '\n';
    }

    return 0;
}