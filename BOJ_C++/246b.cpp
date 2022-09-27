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
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(10);
    // cout << a / hypot(a, b) << ' ' << b / hypot(a, b) << '\n';
    double theta = atan2(b, a);
    cout << cos(theta) << ' ' << sin(theta) << '\n';
    return 0;
}