#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
bool col[40], ldia[40], rdia[40];
int ans[16];
void init() {
    for(int i = 0; i < 40; i++) {
        col[i] = ldia[i] = rdia[i] = false;
    }
    for(int i = 0; i < 16; i++) {
        ans[i] = -1;
    }
}
void printans() {
    for(int i = 0; i < n; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
    return ;
}
bool go(int now) {
    if(now == n) {
        printans();
        return true;
    }


    for(int i = 0; i < n; i++) {
        if(!col[i] && !ldia[i + now] && !rdia[i - now + n]) {
            col[i] = ldia[i + now] = rdia[i - now + n] = true;
            ans[now] = i;
            if(go(now + 1)) return true;
            col[i] = ldia[i + now] = rdia[i - now + n] = false;
            ans[now] = -1;
        }
    }
    return false;
}
void solve() {
    init();
    cin >> n;
    go(0);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}