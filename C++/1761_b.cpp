#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        ++mp[tmp];
    }

    if(mp.size() > 2) {
        cout << n << '\n';
    } else {
        cout << n / 2 + 1 << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}