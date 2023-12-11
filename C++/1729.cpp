#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int a[6][6];
int b[6][6];
int change[6];
int ans = 0;
void go(int idx) {
    if(idx == 6) {
        int ret = 0;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                b[i][j] = (a[i][j] + change[i]) % 10;
                ret += b[i][j];
            }
        }
        
        for(int i = 0; i < 6; i++) {
            int mx = -1;
            for(int j = 0; j < 6; j++) {
                if(i == j || j == 5 - i) continue;
                mx = max(mx, b[j][i]);
            }
            ret += (9 - mx) * 4;
            int t1 = b[i][i], t2 = b[5 - i][i];
            b[i][i] += (9 - mx);
            b[i][i] %= 10;
            b[5 - i][i] += (9 - mx);
            b[5 - i][i] %= 10;
            ret += b[i][i] - t1 + b[5 - i][i] - t2;
        }

        int mx1 = -1, mx2 = -1;
        for(int i = 0; i < 6; i++) {
            mx1 = max(mx1, b[i][i]);
            mx2 = max(mx2, b[5 - i][i]);
        }
        ret += (9 - mx1) * 6;
        ret += (9 - mx2) * 6;

        ans = max(ans, ret);
        return ;
    }
    
    for(int i = 0; i < 10; i++) {
        change[idx] = i;
        go(idx + 1);
    }
}
int main() {
    fastio;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> a[i][j];
        }
    }

    go(0);
    cout << ans << '\n';
    return 0;
}