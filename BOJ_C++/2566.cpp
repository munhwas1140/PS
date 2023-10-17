#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<vector<int>> a(9, vector<int>(9, 0));
    int now = -1;
    int x, y;
    x = y = -1;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if(now < a[i][j]) {
                x = i; y = j;
                now = a[i][j];
            }
        }
    }
    cout << now << '\n';
    cout << x + 1 << ' ' << y + 1 << '\n';

    return 0;
}