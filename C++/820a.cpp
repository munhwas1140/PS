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
    int tc; cin>> tc;
    while(tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ta = abs(a - 1);
        int tb = abs(c - b) + abs(c - 1);
        if(ta < tb) {
            cout << 1 << '\n';
        } else if(ta == tb) {
            cout << 3 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }

    return 0;
}