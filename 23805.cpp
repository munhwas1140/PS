#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n * 5, string(5 * n, '@'));
    for(int i = 0; i < n * 4; i++) {
        for(int j = 0; j < n; j++) {
            a[i][3 * n + j] = ' ';
            a[n * 5 - i - 1][n + j] = ' ';
        }
    }
    for(int i = 0; i < n * 5; i++) {
        cout << a[i] << '\n';
    }

    return 0;
}