#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    for(int i = -999; i <= 999; i++) {
        for(int j = -999; j <= 999; j++) {
            if(a * i + b * j == c && d * i + e * j == f) {
                return !(cout << i << ' ' << j << '\n');
            }
        }
    }
    return 0;
}