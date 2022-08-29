#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[10][10];
int num[6] = {0,5,5,5,5,5};
int go(int idx) {
    if(idx == 100) return 0;
    
    int x = idx / 10;
    int y = idx % 10;

    int ret = 1e9;
    if(a[x][y] == 0) {
        ret = min(ret, go(idx + 1));
    } else {
        int mx = min({5, 10-x, 10-y});
        for(int sz = mx; sz >= 1; sz--) {
            if(num[sz] == 0) continue;
            int cnt = 0;
            for(int i = 0; i < sz; i++) {
                for(int j = 0; j < sz; j++) {
                    cnt += a[x+i][y+j];
                }
            }
            if(cnt == sz * sz) {
                for(int i = 0; i < sz; i++) {
                    for(int j = 0; j < sz; j++) {
                        a[x+i][y+j] = 0;
                    }
                }
                num[sz] -= 1;
                ret = min(ret, go(idx + sz) + 1);
                for(int i = 0; i < sz; i++) {
                    for(int j = 0; j < sz; j++) {
                        a[x+i][y+j] = 1;
                    }
                }
                num[sz] += 1;
            }
        }
    }
    return ret;
}
int main() {
    fastio;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >>a[i][j];
        }
    }

    int ans = go(0);
    if(ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n'; 
      
    return 0;
}