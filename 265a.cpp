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
    int x, y, n;
    int ans = 0;
    cin >> x >> y >> n;
    if(x * 3 > y) {
        ans = y * (n / 3) + x * (n % 3);
    } else ans = x * n;
    cout << ans << '\n';
    return 0;
}