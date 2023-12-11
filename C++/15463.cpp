#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    vector<vector<bool>> mp(2001, vector<bool>(2001, false));

    int ans = 0;
    for(int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000; x2 += 1000; y1 += 1000; y2 += 1000;
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                mp[x][y] = true;
                ans++;
            }
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000; y1 += 1000; x2 += 1000; y2 += 1000;
    for(int x = x1; x < x2; x++) {
        for(int y = y1; y < y2; y++) {
            if(mp[x][y]) ans--;
        }
    }
    cout << ans << '\n';

    return 0;
}