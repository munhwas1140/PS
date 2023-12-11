#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, ans;
int a[200001];
void go(int now, ll h, int g, int b) {
    ans = max(ans, now);
    if(now >= n) return ;


    if(a[now] >= h) {
        if(g) {
            go(now, h * 2, g - 1, b);
        }
        if(b) {
            go(now, h * 3, g, b - 1);
        }
        if(!b && !g) return ;
    } else {
        go(now + 1, h + a[now] / 2, g, b);
    }

}
void solve() {
    ll h;
    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    ans = 0;
    go(0,h,2,1);
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}