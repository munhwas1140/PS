#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string tmp = "FBFFBFFBFBFFBFFBFBFFBFFB";
void solve() {
    int n; string str;
    cin >> n >> str;
    if(tmp.find(str) != string::npos) cout << "YES" <<'\n';
    else cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}