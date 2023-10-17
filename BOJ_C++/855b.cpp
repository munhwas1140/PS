#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, p;
    cin >> n >> p;
    int ans = p;
    if(n >= 5) ans = min(ans, p - 500);
    if(n >= 10) ans = min(ans, (p / 10) * 9);
    if(n >= 15) ans = min(ans, p - 2000);
    if(n >= 20) ans = min(ans, (p / 100) * 75);
    if(ans < 0) ans = 0;
    cout << ans << '\n';
    return 0;
}