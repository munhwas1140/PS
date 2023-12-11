#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int p[10000001];
const ll MAX = 1e7;
int main() {
    fastio;
    for(int i = 2; i <= 10000000; i++) {
        if(!p[i]) {
            for(int j = i; j <= 10000000; j += i) {
                p[j] = i;
            }
        }
    }

    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        int d = y - x;
        if(d == 1) {
            cout << -1 << '\n';
            continue;
        }

        int ans = -1;
        while(d >= 2) {
            int now = p[d];
            while(d % now == 0) d /= now;
            int tmp = x % now;
            if(tmp > 0) tmp = now - tmp;
            if(ans == -1 || ans > tmp) ans = tmp;
        }
        cout << ans << '\n';
    }

    return 0;
}