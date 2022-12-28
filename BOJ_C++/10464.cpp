#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int go(int x) {
    int tmp = x % 4;
    if(tmp == 0) return x;
    else if(tmp == 1) return 1;
    else if(tmp == 2) return x + 1;
    else return 0;
}
void solve() {
    int s, e;
    cin >> s >> e;
    cout << (go(e) ^ go(s - 1)) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}