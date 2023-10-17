#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
void go(int n, ull k, int a, int b, int c) {
    if(n == 1) {
        cout << a << ' ' << c << '\n';
        return ;
    }
    ull tmp = (1ULL << (n - 1)) - 1;
    if(k <= tmp) {
        go(n - 1, k, a, c, b);
    } else {
        if(k == tmp + 1) {
            cout << a << ' ' << c << '\n';
            return ;
        }
        go(n - 1, k - tmp - 1, b, a, c);
    }
}
void solve() {
    int n;
    ull k;
    cin >> n >> k;
    go(n, k, 1, 2, 3);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}