#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int x; cin >> x;
        int tmp = 1;
        for(int i = 1; i; i++) {
            if(x - tmp * 9 >= 0) {
                x -= tmp * 9;
            } else {
                x /= tmp;
                int k = x / tmp;
                tmp += k - 1;
                to_string(tmp);

            }
            tmp *= 10;
        }
    }
    return 0;
}