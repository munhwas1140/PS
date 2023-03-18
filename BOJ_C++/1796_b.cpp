#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(a[i] == b[j] && a[i + 1] == b[j + 1]) {
                cout << "YES" << '\n';
                cout << '*' << a[i] << a[i + 1] << '*' << '\n';
                return ;
            }
        }
    }

    if(a[0] == b[0]) {
        cout << "YES" << '\n';
        cout << a[0] << '*' << '\n';
        return ;
    } else if(a[n - 1] == b[m - 1]) {
        cout << "YES" << '\n';
        cout << '*' << a[n - 1] << '\n';
        return ;
    }
    cout << "NO" << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}