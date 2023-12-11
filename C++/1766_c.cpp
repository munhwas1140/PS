#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt, n;
bool check(vector<string> a, int x, int y) {
    vector<bool> visited(n);
    while(y < n) {
        if(a[x][y] == 'W') {
            return false;
        }
        visited[y] = true;
        a[x][y] = 'W';
        if(a[1 - x][y] == 'B') {
            x = 1 - x;
        } else {
            y++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) return false;
    }
    return true;
}
void solve() {
    cin >> n;
    vector<string> a(2);
    for(int i = 0; i < 2; i++) {
        cin >> a[i];
    }

    if(a[0][0] == 'W' && a[1][0] == 'W') {
        cout << "NO" << '\n';
        return ;
    }

    bool ok;
    if(a[0][0] == 'B' && a[1][0] == 'B') {
        ok = check(a, 0, 0) || check(a, 1, 0);
    } else if(a[0][0] == 'B') {
        ok = check(a, 0, 0);
    } else if(a[1][0] == 'B') {
        ok = check(a, 1, 0);
    }
    if(ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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