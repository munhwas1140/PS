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
    int n;
    cin >> n;
    ll d[2][30];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                cout << (d[i%2][j] = 1) << ' ';
            } else {
                cout << (d[i%2][j] = d[1-i%2][j] + d[1-i%2][j-1]) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}