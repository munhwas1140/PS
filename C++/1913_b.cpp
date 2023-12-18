#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int n = str.size();
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '0') zero++;
        else one++;
    }
    int it = 0;
    while(it < n) {
        if(str[it] == '1') {
            if(zero > 0) zero--;
            else break;
        } else {
            if(one > 0) one--;
            else break;
        }
        it++;
    }
    cout << n - it << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}