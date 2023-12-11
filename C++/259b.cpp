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
    double a, b, d;
    cin >> a >> b >> d;
    double r = hypot(a, b);
    double theta = atan2(b, a);

    theta += d * acos(-1.0) / 180.0;

    double x = cos(theta) * r;
    double y = sin(theta) * r;
    
    cout << fixed << setprecision(10) << x << ' ' << y << '\n';
    return 0;
}
