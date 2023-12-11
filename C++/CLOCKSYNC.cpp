#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int sw[10][10] = {
    {0,1,2,-1},
    {3,7,9,11,-1},
    {4,10,14,15,-1},
    {0,4,5,6,7,-1},
    {6,7,8,10,12,-1},
    {0,2,14,15,-1},
    {3,14,15,-1},
    {4,5,7,14,15,-1},
    {1,2,3,4,5,-1},
    {3,4,5,9,13,-1},
};
int go(vector<int> &a, int idx) {
    if(idx == 10) {
        bool ok = true;
        for(int i = 0; i < 16; i++) {
            if(a[i] != 12) ok = false;
        }
        if(ok) return 0;
        return 1e9;
    }
    
    int ret = 1e9;
    for(int i = 0; i < 4; i++) {
        ret = min(ret, i + go(a, idx + 1));
        for(int j = 0; j < 10; j++) {
            if(sw[idx][j] == -1) break;
            a[sw[idx][j]] += 3;
            if(a[sw[idx][j]] == 15) {
                a[sw[idx][j]] = 3;
            }
        }
    }
    return ret;
}
void solve() {
    vector<int> a(16);
    for(int i = 0; i < 16; i++) {
        cin >> a[i];
    }
    int ans = go(a, 0);
    if(ans == 1e9) ans = -1;
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