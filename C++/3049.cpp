#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    if(n == 3) cout << 0 << '\n';
    else {
        cout << n * (n - 1) * (n - 2) * (n - 3) / 24 << '\n';
    }
    return 0;
}