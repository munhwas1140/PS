#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str;
    cin >> str;
    int sz = str.size();

    for(int i = 1; i < sz / 2; i++) {
        if(str[i] != '0') {
            cout << str.substr(0, i) << ' ' << str.substr(i) << '\n';
            return ;
        }
    }

    if(sz % 2 == 1) {
        if(str[sz / 2] != '0') {
            int l = stoi(str.substr(0, sz / 2));
            int r = stoi(str.substr(sz / 2));
            cout << l << ' ' << r << '\n';
            return ;
        }
    } else {
        if(str[sz / 2] != '0') {
            int l = stoi(str.substr(0, sz / 2));
            int r = stoi(str.substr(sz / 2));
            if(l < r) {
                cout << l << ' ' << r << '\n';
                return ;
            }
        }
    }
    cout << -1 << '\n';

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}