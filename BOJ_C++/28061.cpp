#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        int tmp; cin >> tmp;
        ans = max(ans, tmp - i);
    }
    cout << ans << '\n';

    return 0;
}