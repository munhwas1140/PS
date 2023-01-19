#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    int now = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp == now) {
            ans++;
            now++;
            now %= 3;
        }
    }
    cout << ans << '\n';
    return 0;
}