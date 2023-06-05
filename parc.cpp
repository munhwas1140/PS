#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[1001];
void solve() {
    int n, m;
    cin >> n >> m;
    if(check[m] == false) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << i * m + j + 1 << ' ';
            }
            cout << '\n';
        }
    } else if(check[n] == false) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << i + j * n + 1 << ' ';
            }
            cout << '\n';
        }
    } else {
        bool f = true;
        if(n > m) {
            f = false;
            swap(n, m);
        }
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = i * m + j + 1;
            }
            reverse(a[i].begin(), a[i].begin() + i);
            reverse(a[i].begin() + i, a[i].end());
            reverse(a[i].begin(), a[i].end());
        }
        if(f) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            for(int j = 0; j < m; j++) {
                for(int i = 0; i < n; i++) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }


        }
    }

}
int main() {
    fill(check,check + 1001, true);
    check[0] = false;
    for(int i = 2; i <= 1000; i++) {
        if(check[i]) {
            for(int j = i + i; j <= 1000; j += i) {
                check[j] = false;
            }
        }
    }
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}