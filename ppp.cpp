#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            if(i == 300) {
                if(j == 301 || j == 300) {
                    cout << 'O';
                }
            } else {
                cout << 'q';
            }
        }
        cout << '\n';
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