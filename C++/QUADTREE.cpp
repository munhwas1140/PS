#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string go(string::iterator &it) {
    char now = *it;
    ++it;
    if(now == 'b' || now == 'w') {
        return string(1,now);
    }

    string ul = go(it);
    string ur = go(it);
    string dl = go(it);
    string dr = go(it);
    return string("x") + dl + dr + ul + ur;
}
void solve() {
    string str; cin >> str;
    auto it = str.begin();
    cout << go(it) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}