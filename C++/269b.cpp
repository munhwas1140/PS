#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    vector<string> a(11);
    for(int i = 1; i < 11 ; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    int x1, y1, x2, y2;
    x1 = y1 = 1e9;
    x2 = y2 = -1;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(a[i][j] == '#') {
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
            }
        }
    }
    cout << x1 << ' ' << x2 << '\n' << y1 << ' ' << y2 << '\n';
    return 0;
}