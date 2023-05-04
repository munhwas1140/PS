#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<int> c(101);
    for(int i = 0; i <= 100; i++) {
        c[i] = pow(i, 3);
    }
    for(int i = 2; i <= 100; i++) {
        for(int x = 2; x <= 100; x++) {
            for(int y = x; y <= 100; y++) {
                for(int z = y; z <= 100; z++) {
                    if(c[i] == c[x] + c[y] + c[z]) {
                        cout << "Cube = " << i << ", Triple = (";
                        cout << x << ',' << y << ',' << z << ")\n";
                    }
                }
            }
        }

    }
    return 0;
}