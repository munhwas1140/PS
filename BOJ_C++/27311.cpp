#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int mnx, mny, mxx, mxy;
    mnx = mny = 1e9;
    mxx = mxy = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '#') {
                mxx = max(mxx, i);
                mxy = max(mxy, j);
                mnx = min(mnx, i);
                mny = min(mny, j);
            }
        }
    }

    if(mnx == 1e9) {
        cout << 0 << '\n';
        return ;
    }
    int cnt = 0;
    for(int i = mnx; i <= mxx; i++) {
        for(int j = mny; j <= mxy; j++) {
            if(a[i][j] == '.')  cnt++;
        }
    }

    if(sqrt(cnt) == int(sqrt(cnt))) {
        int r = sqrt(cnt);
        
        int t[4] = {0};
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < r; j++) {
                if(mnx + i < n && mny + j < m && a[mnx + i][mny + j] == '.') t[0]++;
                if(mnx + i < n && mxy - j >= 0 && a[mnx + i][mxy - j] == '.') t[1]++;
                if(mxx - i >= 0 && mny + j < m && a[mxx - i][mny + j] == '.') t[2]++;
                if(mxx - i >= 0 && mxy - j >= 0 && a[mxx - i][mxy - j] == '.') t[3]++;
            }
        }

        for(int i = 0; i < 4; i++) {
            if(t[i] == cnt) {
                cout << 1 << '\n';
                return ;
            }
        }
        cout << 0 << '\n';
    } else {
        cout << 0 << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}