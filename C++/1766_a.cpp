#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check(int now) {
    int cnt = 0;
    while(now) {
        if(now % 10) cnt++;
        now /= 10;
    }
    return (cnt == 1);
}
int p[1000000];

void solve() {
    int n; cin >> n;
    cout << p[n] << '\n';
}
int main() {
    for(int i = 1; i < 1000000; i++) {
        p[i] = p[i - 1] + check(i);
    }

    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}