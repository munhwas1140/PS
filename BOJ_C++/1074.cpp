#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll go(int n, int r, int c) {
    if(n == 1) {
        return 2 * r + c;
    }

    ll now = (1 << (n - 1));
    ll sum = now * now;
    if(r >= now) {
        if(c >= now) {
            return 3 * sum + go(n - 1, r - now, c - now);
        } else {
            return 2 * sum + go(n - 1, r - now, c);
        }
    } else {
        if(c >= now) {
            return sum + go(n - 1, r, c - now);
        } else {
            return go(n - 1, r, c);
        }
    }
}
int main() {
    fastio;
    int n, r, c;
    cin >> n >> r >> c;
    cout << go(n, r, c) - 1 << '\n';
    return 0;
}