#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[2][2];
bool check() {
    for(int i = 0; i < 2; i++) {
        if(a[i][0] > a[i][1]) return false;
        if(a[0][i] > a[1][i]) return false;
    }
    return true;
}
void rot() {
    int tmp = a[0][0];
    a[0][0] = a[1][0];
    a[1][0] = a[1][1];
    a[1][1] = a[0][1];
    a[0][1] = tmp;
}
void solve() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        if(check()) {
            cout << "YES" << '\n';
            return ;
        }
        rot();
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