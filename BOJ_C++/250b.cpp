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
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        for(int l = 0; l < a; l++) {
            for(int j = 0; j < n; j++) {
                if((i + j) % 2 == 0) {
                    for(int k = 0; k < b; k++) {
                        cout << '.';
                    }
                } else {
                    for(int k = 0; k < b; k++) {
                        cout << '#';
                    }
                }
            }
        cout << '\n';
        }
    }

    return 0;
}