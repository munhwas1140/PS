#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int a = str[0] - '0';
    int b = str[2] - '0';
    cout << a + b << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}