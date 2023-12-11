#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, rpsum[100002], lpsum[100002];
string str;
void solve() {
    cin >> n >> str;
    int it = 0;
    while(it < n && str[it] == '0') it++;
    if(it == n) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    for(; it < n - 1; it++) {
        if(str[it] != str[it + 1]) ans++;
    }
    cout << ans << '\n';

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}