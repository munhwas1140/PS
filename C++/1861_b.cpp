#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string a, b;
    cin >> a >> b;
    string tmp = "01";

    int n = a.size();
    for(int i = 0; i < n - 1; i++) {
        string t1 = a.substr(i, 2);
        string t2 = b.substr(i, 2);
        if(t1 == tmp && t2 == tmp) {
            cout << "YES" << '\n';
            return ;
        }
    }
    cout << "NO" << '\n';
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}