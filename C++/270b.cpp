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
    int x, y, z;
    cin >> x >> y >> z;
    //x = goal, y = wall, z = hammer;

    if(abs(y) >= abs(x)) {
        cout << abs(x) << '\n';
    } else {
        if(x * y < 0) {
            cout << abs(x) << '\n';
        } else {
            if(y * z > 0 && abs(z) > abs(y)) {
                cout << -1 << '\n';
            } else {
                cout << abs(z) + abs(z - y) + abs(y - x) << '\n';
            }
        }
    }

    return 0;
}