#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int x, y, d, t;
    cin >> x >> y >> d >> t;
    cout << fixed << setprecision(10);
    if(sqrt(2 * d * d) <= t * 2.0) {
        cout << sqrt(x * x + y * y) << '\n';
    } else {
        double ans = sqrt(x * x + y * y);
        for(int i = 1; i <= 10000; i++) {
            ans = min(ans, 2.0 * t + sqrt((x - i * d) * (x - i * d) + (y - i * d) * (y - i * d)));
        }    
        cout << ans << '\n';
    }

    return 0;
}